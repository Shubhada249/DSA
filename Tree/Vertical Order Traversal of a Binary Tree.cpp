//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

//TC:O(n log n)     //SC:O(n)
void fun(TreeNode* root,int c,int r,multiset<pair<int,pair<int,int>>> &st)
    {
        if(!root)
            return;
        fun(root->left,c-1,r+1,st);
        st.insert({c,{r,root->val}});
        fun(root->right,c+1,r+1,st);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        multiset<pair<int,pair<int,int>>> st;
        fun(root,0,0,st);
        auto i=st.begin();
        int p=i->first;
        
        i=st.end();
        i--;
        int q=i->first;
        vector<vector<int>> ans(q-p+1);
        int a=0-p;
        for(auto it:st)
        {
            ans[it.first+a].push_back(it.second.second);
        }
        return ans;
    }