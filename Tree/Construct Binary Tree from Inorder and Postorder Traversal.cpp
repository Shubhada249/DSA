//https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
//TC:O(n)   //SC:O(n)
TreeNode* fun(int is,int ie,int ps,int pe,vector<int>& in, vector<int>& po,unordered_map<int,int> &mp)
    {
        if(is>ie || ps>pe)
            return NULL;
        TreeNode* root=new TreeNode(po[pe]);
        int ind=mp[root->val];
        root->left=fun(is,ind-1,ps,ind-is+ps-1,in,po,mp);
        root->right=fun(ind+1,ie,ind-is+ps,pe-1,in,po,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& po) {
        unordered_map<int,int> mp;
        int n=in.size();
        for(int i=0;i<n;i++)
        {
            mp[in[i]]=i;
        }
       