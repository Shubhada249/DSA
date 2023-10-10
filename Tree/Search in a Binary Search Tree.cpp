
//https://leetcode.com/problems/search-in-a-binary-search-tree/

//TC:O(log n)   //SC:O(log n)
TreeNode* searchBST(TreeNode* root, int val) {
        if(!root)
            return NULL;
        if(root->val==val)
            return root;
        return (val<root->val)?searchBST(root->left,val):searchBST(root->right,val);     
    }

//TC:O(log n)   //SC:O(1)
TreeNode* searchBST(TreeNode* root, int val) {
        while(root)
        {
            if(root->val==val)
                return root;
            if(val<root->val)
                root=root->left;
            else
                root=root->right;
        }
        return NULL;
    }