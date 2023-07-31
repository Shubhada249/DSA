//https://leetcode.com/problems/binary-tree-preorder-traversal/

//TC:O(n)   //SC:O(n)
void fun(TreeNode* root,vector<int> &ans)
    {
        if(!root)
            return;
        ans.push_back(root->val);
        fun(root->left,ans);
        fun(root->right,ans);        
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;

        TreeNode* cur=root;
        while(!st.empty() || cur)
        {
            if(cur)
            {
                ans.push_back(cur->val);
                st.push(cur);
                cur=cur->left;
            }
            else
            {
                cur=st.top()->right;
                st.pop();
            }
        }
        return ans;
    }