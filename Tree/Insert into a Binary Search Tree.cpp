//https://leetcode.com/problems/insert-into-a-binary-search-tree/

//TC:o(n)   //SC:O(n)
TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
            return new TreeNode(val);
        if(val<root->val)
            root->left=insertIntoBST(root->left,val);
        else
            root->right=insertIntoBST(root->right,val);
        return root;
    }

//TC:o(n)   //SC:O(1)
TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
            return new TreeNode(val);
        TreeNode *cur=root,*prev=root;
        while(cur)
        {
            prev=cur;
            if(val<cur->val)
                cur=cur->left;
            else
                cur=cur->right;
        }
        if(val<prev->val)
            prev->left=new TreeNode(val);
        else
            prev->right=new TreeNode(val);
        return root;
    }