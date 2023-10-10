//https://leetcode.com/problems/diameter-of-binary-tree/

//TC:O(n)   //SC:O(n)
int fun(TreeNode* root,int &ans)
    {
        if(!root)
            return 0;
        int a=fun(root->left,ans);
        int b=fun(root->right,ans);
        ans=max(ans,a+b);
        return 1+max(a,b);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        int ht=fun(root,ans);
        return ans;
    }