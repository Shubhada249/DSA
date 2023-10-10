//https://leetcode.com/problems/validate-binary-search-tree/
//TC:O(n^2)   //SC:O(n)
bool rmnolst(TreeNode* root,TreeNode* rt)
    {
        if(!root)
            return true;
        while(root->right)
            root=root->right;
        return root->val<rt->val;
    }
    bool lmnorst(TreeNode* root,TreeNode* rt)
    {
        if(!root)
            return true;
        while(root->left)
            root=root->left;
        return root->val>rt->val;
    }
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        return isValidBST(root->left) && isValidBST(root->right) && rmnolst(root->left,root) && lmnorst(root->right,root);
    }


//TC:O(n)   //SC:O(n)
bool inorder(TreeNode* root,long long &prev)
    {
        if(!root)
            return true;
        if(!inorder(root->left,prev))
            return false;
        if(prev>=root->val)
            return false;
        prev=root->val;
        if(!inorder(root->right,prev))
            return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        long long prev=(long long)INT_MIN-1;
        return inorder(root,prev);
        
    }