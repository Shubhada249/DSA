//https://leetcode.com/problems/binary-tree-maximum-path-sum/

//Edge case:negative values of nodes
//TC:O(n)   //SC:O(n)
int fun(TreeNode* root,int &ans)
    {
        if(!root)
            return 0;
        int a=fun(root->left,ans);
        int b=fun(root->right,ans);
        int temp=root->val;
        if(a>0)
            temp+=a;
        if(b>0)
            temp+=b;
        ans=max(ans,temp);
        return root->val+max(0,(max(a,b)));
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        int temp=fun(root,ans);
        return ans;
    }