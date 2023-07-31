//https://leetcode.com/problems/binary-tree-inorder-traversal/

//TC:O(n)   //SC:O(n)
void fun(TreeNode* root,vector<int> &ans)
    {
        if(!root)
            return ;
        fun(root->left,ans);
        ans.push_back(root->val);
        fun(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* cur=root;
        while(!st.empty() || cur)
        {
            if(cur)
            {
                st.push(cur);
                cur=cur->left;
            }
            else
            {
                ans.push_back(st.top()->val);
                cur=st.top()->right;
                st.pop();
            }
        }
        return ans;
    }