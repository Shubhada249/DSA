//https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//TC:O(n)   //SC:O(n)
vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> ans;
        unordered_map<int,int> mp;
        int minc=INT_MAX;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            Node* f=q.front().first;
            int c=q.front().second;
            minc=min(c,minc);
            if(f->left)
                q.push({f->left,c-1});
            if(f->right)
                q.push({f->right,c+1});
            if(mp.find(c)==mp.end())
                mp[c]=f->data;
            q.pop();
        }

        int s=mp.size()+minc;
        for(int i=minc;i<(s);i++)
        {
            ans.push_back(mp[i]);
        }
        return ans;
    }