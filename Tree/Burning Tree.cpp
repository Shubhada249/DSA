//https://practice.geeksforgeeks.org/problems/burning-tree/1

//TC:O(2n)  //SC:O(4n)
void findParent(Node* root,unordered_map<Node*,Node*> &mp,int target,Node* &t)
    {
        queue<Node*> q;
        q.push(root);
        mp[root]=NULL;
        while(!q.empty())
        {
            Node* f=q.front();
            if(f->data==target)
                t=f;
            if(f->left)
            {
                q.push(f->left);
                mp[f->left]=f;
            }
            if(f->right)
            {
                q.push(f->right);
                mp[f->right]=f;
            }
            q.pop();
        }
    }
    int bfs(Node *t,unordered_map<Node*,Node*> &mp,unordered_set<Node *> &v)
    {
        int ans=-1;
        queue<Node*> q;
        q.push(t);
        v.insert(t);
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                Node *f=q.front();
                if(f->left && v.find(f->left)==v.end())
                {
                    q.push(f->left);
                    v.insert(f->left);
                }
                if(f->right && v.find(f->right)==v.end())
                {
                    q.push(f->right);
                    v.insert(f->right);
                }
                if(mp[f] && v.find(mp[f])==v.end())
                {
                    q.push(mp[f]);
                    v.insert(mp[f]);
                }
                q.pop();
            }
            ans++;
        }
        return ans;
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<Node*,Node*> mp;
        Node* t;
        findParent(root,mp,target,t);
        unordered_set<Node *> v;
        return bfs(t,mp,v);
    }