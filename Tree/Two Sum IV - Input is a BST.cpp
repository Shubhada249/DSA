//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
//TC:O(2n)  //SC:O(2n)
void inorder(TreeNode* root,vector<int> &v)
    {
        if(!root)
            return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        inorder(root,v);
        int n=v.size();
        for(int i=0,j=n-1;i<j;)
        {
            if(v[i]+v[j]==k)
                return true;
            if(v[i]+v[j]<k)
                i++;
            else
                j--;
        }
        return false;  
    }

//TC:O(n)  //SC:O(2h)
TreeNode* next(stack<TreeNode *> &st1)
    {
        TreeNode *ans=st1.top(),*cur;
        st1.pop();
        cur=ans->right;
        while(cur)
        {
            st1.push(cur);
            cur=cur->left;
        }
        return ans;
    }
    TreeNode* prev(stack<TreeNode *> &st2)
    {
        TreeNode *ans=st2.top(),*cur;
        st2.pop();
        cur=ans->left;
        while(cur)
        {
            st2.push(cur);
            cur=cur->right;
        }
        return ans;
    }
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode *> st1,st2;
        TreeNode *cur=root,*l,*r;
        while(cur)
        {
            st1.push(cur);
            cur=cur->left;
        }
        cur=root;
        while(cur)
        {
            st2.push(cur);
            cur=cur->right;
        }
        l=next(st1);
        r=prev(st2);
        while(l!=r)
        {
            if(l->val+r->val==k)
                return true;
            if(l->val+r->val<k)
                l=next(st1);
            else
                r=prev(st2);
        }
        return false;
    }