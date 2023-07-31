//https://leetcode.com/problems/binary-tree-postorder-traversal/
//TC:O(n)   //SC:O(n)
void fun(TreeNode* root,vector<int> &ans)
    {
        if(!root)
            return ;
        fun(root->left,ans);
        fun(root->right,ans);
        ans.push_back(root->val);
    }
//TC:O(n)   //SC:O(n)
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<pair<TreeNode*,int>> st;
        TreeNode* cur=root;
        while(!st.empty() || cur)
        {
            if(cur)
            {
                st.push({cur,0});
                cur=cur->left;
            }
            else
            {
                if(st.top().second==0)
                {
                    cur=st.top().first->right;
                    st.top().second=1;
                }
                else
                {
                    ans.push_back(st.top().first->val);
                    st.pop();
                }
            }
        }
        return ans;
    }