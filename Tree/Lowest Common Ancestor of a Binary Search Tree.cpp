//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

//TC:O(height of BST)   //SC:O(1)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(q->val < p->val)
        {
            TreeNode* temp=p;
            p=q;
            q=temp;
        }
        TreeNode* cur=root;
        while(cur)
        {
            if(p->val < cur->val && q->val > cur->val)
                return cur;
            if(p->val == cur->val || q->val == cur->val)
                return cur;
            if(q->val < cur->val)
                cur=cur->left;
            else
                cur=cur->right;
        }
        return NULL;
    }