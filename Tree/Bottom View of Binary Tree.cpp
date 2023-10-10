//https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
//TC:O(n log n)     //SC:O(n)
void fun(Node *root, map<int,int> &mp)
    {
        queue<pair<Node *,int>> q;
        if(root)
            q.push({root,0});
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                Node *temp=q.front().first;
                int c=q.front().second;
                if(temp->left)
                    q.push({temp->left,c-1});
                if(temp->right)
                    q.push({temp->right,c+1});
                mp[c]=temp->data;
                q.pop();
            }
        }
    }
    vector <int> bottomView(Node *root) {
        // Your Code Here
        map<int,int> mp;
        fun(root,mp);
        vector <int> ans;
        for(auto it:mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }