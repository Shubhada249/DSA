//https://leetcode.com/problems/balanced-binary-tree/

//TC:O(2n)   //SC:o(2n)
bool fun(TreeNode* root,unordered_map<TreeNode*,int> &mp)
    {
        if(!root)
            return true;
        if(fun(root->left,mp) && fun(root->right,mp) && abs(mp[root->left]-mp[root->right])<=1)
            return true;
        return false;
    }
    int ht(TreeNode* root,unordered_map<TreeNode*,int> &mp)
    {
        if(!root)
            return mp[root]=0;
        return mp[root]=1+max(ht(root->left,mp),ht(root->right,mp));            
    }
    bool isBalanced(TreeNode* root) {
        unordered_map<TreeNode*,int> mp;
        int h=ht(root,mp);
        return fun(root,mp);
    }

//TC:O(n)   //SC:o(n)
int fun(TreeNode* root)
    {
        if(!root)
            return 0;
        int a=fun(root->left);
        int b=fun(root->right);
        if(a!=-1 && b!=-1 && abs(a-b)<=1)
            return 1+max(a,b);
        return -1;
            
    }
    bool isBalanced(TreeNode* root) {
        if(fun(root)==-1)
            return false;
        return true;
    }