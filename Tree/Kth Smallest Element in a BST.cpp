//https://leetcode.com/problems/kth-smallest-element-in-a-bst/

//TC:O(n)   //SC:O(n)
void fun(TreeNode* root, int &k,int &ans)
    {
        if(!root || k==0)
            return;
        fun(root->left,k,ans);
        if(k==1)
        {
            ans=root->val;            
        }
        k--;
        fun(root->right,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        fun(root,k,ans);
        return ans;
    }