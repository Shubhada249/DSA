//https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

//TC:O(n log n)     //SC:O(2n)
TreeNode* fun(int is,int ie,int ps,int pe,vector<int>& pre,unordered_map<int,int> &mp)
    {
        if(is>ie || ps>pe)
            return NULL;
        TreeNode *root=new TreeNode(pre[ps]);
        int i=mp[pre[ps]];
        root->left=fun(is,i-1,ps+1,i-is+ps,pre,mp);
        root->right=fun(i+1,ie,i-is+ps+1,pe,pre,mp);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        vector<int> in=pre;
        int n=pre.size();
        sort(in.begin(),in.end());
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[in[i]]=i;
        }
        return fun(0,n-1,0,n-1,pre,mp);
    }

//TC:O(n)   //SC:O(n)
TreeNode* fun(vector<int>& pre,int &i,int ub)
    {
        if(i=pre.size()||pre[i]>=ub)
            return NULL;
        TreeNode *root=new TreeNode(pre[i]);
        i++;
        root->left=fun(pre,i,root->val);
        root->right=fun(pre,i,ub);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        int i=0;
        return fun(pre,i,INT_MAX);
    }