//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

//TC:O(n)   //SC:O(n)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q)
            return root;
        TreeNode* l=lowestCommonAncestor(root->left,p,q);
        TreeNode* r=lowestCommonAncestor(root->right,p,q);
        if(l && r)
            return root;
        if(l)
            return l;
        if(r)
            return r;
        return NULL;
    }