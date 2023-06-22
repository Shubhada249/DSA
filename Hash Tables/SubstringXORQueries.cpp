//https://leetcode.com/problems/substring-xor-queries/

//TC:O(n*30+k)   //SC:O(n*30)->map 
vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        vector<vector<int>> ans;
        int n=s.size(),i,j;
        unordered_map<int,pair<int,int>> mp;
        for(i=0;i<n;i++)
        {
            for(j=i;j<n && j-i+1<=30;j++)       //(j-i+1<=30) -> most imp condition of the question
            {
                string str=s.substr(i,j-i+1);
                int val=stoi(str, 0, 2);
                if(mp.find(val)==mp.end())
                    mp[val]={i,j};
                else
                {
                    int p1=mp[val].first,p2=mp[val].second;
                    if(j-i+1<p2-p1+1)
                    {
                        mp[val]={i,j};
                    }
                    else if(j-i+1==p2-p1+1)
                    {
                        if(i<p1)
                        {
                            mp[val]={i,j};
                        }
                    }
                }
            }
        }
        int k=queries.size();
        for(i=0;i<k;i++)
        {
            int f=queries[i][0],s=queries[i][1];
            int ele=f ^ s;
            if(mp.find(ele)==mp.end())
                ans.push_back({-1,-1});
            else
                ans.push_back({mp[ele].first,mp[ele].second});
        }
        return ans;
    }