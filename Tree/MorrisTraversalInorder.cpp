//https://leetcode.com/problems/binary-tree-inorder-traversal/

//TC:O(n)   //SC:O(1)
bool fun(TreeNode* cur,TreeNode* &rmnolst)
    {
        rmnolst=cur->left;
        while(rmnolst->right && rmnolst->right!=cur)
        {
            rmnolst=rmnolst->right;
        }
        if(!rmnolst->right)
            return false;
        return true;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* cur=root;
        while(cur)
        {
            if(!cur->left)
            {
                ans.push_back(cur->val);
                cur=cur->right;
                continue;
            }
            TreeNode* rmnolst;
            bool ch=fun(cur,rmnolst);
            if(!ch)
            {
                rmnolst->right=cur;
                cur=cur->left;
            }
            else
            {
                rmnolst->right=NULL;
                ans.push_back(cur->val);
                cur=cur->right;
            }
        }
        return ans;
    }