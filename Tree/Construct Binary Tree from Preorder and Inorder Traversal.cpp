//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

//TC:O(n)   //SC:O(n)
TreeNode* fun(int is,int ie,int ps,int pe,vector<int>& pre, vector<int>& in,unordered_map<int,int> &mp)
    {
        if(is>ie || ps>pe)
            return NULL;
        TreeNode* root=new TreeNode(pre[ps]);
        int ind=mp[root->val];//find(in.begin(),in.end(),root->val)-in.begin();
        root->left=fun(is,ind-1,ps+1,ind-is+ps,pre,in,mp);
        root->right=fun(ind+1,ie,ind-is+ps+1,pe,pre,in,mp);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n=in.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[in[i]]=i;
        }
        return fun(0,n-1,0,n-1,pre,in,mp);
    }