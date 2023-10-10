//https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

//Using DFS:
//Note:creating visited set is imp.
//TC:O(2n)  //SC:O(3n)
void findParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &mp)
    {
        if(!root)
            return;
        if(root->left)
            mp[root->left]=root;
        if(root->right)
            mp[root->right]=root;
        findParent(root->left,mp);
        findParent(root->right,mp);
    }
    void dfs(TreeNode* cur, int k,vector<int> &ans,unordered_set<TreeNode*> &visited,unordered_map<TreeNode*,TreeNode*> &mp)
    {
        if(!cur)
            return;
        if(visited.find(cur)!=visited.end())
            return;
        if(k==0)
        {
            ans.push_back(cur->val);
            visited.insert(cur);
            return;
        }
        visited.insert(cur);
        dfs(cur->left,k-1,ans,visited,mp);
        dfs(cur->right,k-1,ans,visited,mp);
        dfs(mp[cur],k-1,ans,visited,mp);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> mp;
        findParent(root,mp);
        mp[root]=NULL;
        vector<int> ans;
        unordered_set<TreeNode*> visited;
        dfs(target,k,ans,visited,mp);
        return ans;
    }

//Using BFS:
//Note:creating visited set is imp.
//TC:O(2n)  //SC:O(4n)
void findParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &mp)
    {
        if(!root)
            return;
        if(root->left)
            mp[root->left]=root;
        if(root->right)
            mp[root->right]=root;
        findParent(root->left,mp);
        findParent(root->right,mp);
    }
    void bfs(TreeNode* cur, int k,vector<int> &ans,unordered_set<TreeNode*> &visited,unordered_map<TreeNode*,TreeNode*> &mp)
    {
        queue<TreeNode*> q;
        q.push(cur);
        visited.insert(cur);
        while(!q.empty() && k>0)
        {
            int sz=q.size();
            while(sz--)
            {
                TreeNode* f=q.front();
                if(f->left && visited.find(f->left)==visited.end())
                {
                    q.push(f->left);
                    visited.insert(f->left);
                }
                if(f->right && visited.find(f->right)==visited.end())
                {
                    q.push(f->right);
                    visited.insert(f->right);
                }
                if(mp[f] && visited.find(mp[f])==visited.end())
                {
                    q.push(mp[f]);
                    visited.insert(mp[f]);
                }
                q.pop();
            }
            k--;
        }
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> mp;
        findParent(root,mp);
        mp[root]=NULL;
        vector<int> ans;
        unordered_set<TreeNode*> visited;
        bfs(target,k,ans,visited,mp);
        return ans;
    }