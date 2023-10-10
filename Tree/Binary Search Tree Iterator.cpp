//https://leetcode.com/problems/binary-search-tree-iterator/

class BSTIterator {
public:
    TreeNode *rt,*cur;
    vector<int> v;
    int i=0;
    BSTIterator(TreeNode* root) {
        cur=new TreeNode(-1);
        cur->right=root;
        rt=cur;
        inorder(rt,v);
    }
    void inorder(TreeNode* root,vector<int> &v)
    {
        if(!root)
            return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    //TC:O(1)   //SC:O(n)
    int next() {
        i++;
        return v[i];
    }
    //TC:O(1)   //SC:O(n)
    bool hasNext() {
        if(i+1<v.size())
            return true;
        return false;
    }
};

class BSTIterator {
public:
    stack<TreeNode*> st;
    TreeNode *cur;
    BSTIterator(TreeNode* root) {
        cur=root;
        while(cur)
        {
            st.push(cur);
            cur=cur->left;            
        }
    }
    //TC:O(1)   //SC:O(h)
    int next() {
        TreeNode *ans=st.top();
        st.pop();
        cur=ans->right;
        while(cur)
        {
            st.push(cur);
            cur=cur->left;            
        }
        return ans->val;
    }
    //TC:O(1)   //SC:O(h)
    bool hasNext() {
        if(!st.empty())
            return true;
        return false;
    }
};
