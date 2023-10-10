//https://leetcode.com/problems/count-complete-tree-nodes/

//TC:O((log n)*(log n))     //SC:O(log n)
int lh(TreeNode* root)
    {
        int ans=0;
        while(root)
        {
            ans++;
            root=root->left;
        }
        return ans;
    }
    int rh(TreeNode* root)
    {
        int ans=0;
        while(root)
        {
            ans++;
            root=root->right;
        }
        return ans;
    }
    int countNodes(TreeNode* root) {
        int l=lh(root);
        int r=rh(root);
        if(l==r)
            return (1<<l)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }