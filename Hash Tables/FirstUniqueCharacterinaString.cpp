//https://leetcode.com/problems/first-unique-character-in-a-string/

//TC:O(N^2)  //SC:O(1)
int firstUniqChar(string s) {
        int n=s.size(),j;
        for(int i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i==j)
                    continue;
                if(s[i]==s[j])
                    break;
            }
            if(j==n)
                return i;
        }
        return -1;
    }

//TC:O(3N)  //SC:O(N)
int firstUniqChar(string s) {
        unordered_map<char,pair<int,int>> mp;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(mp.find(s[i])!=mp.end())
            {
                mp[s[i]].first++;
                mp[s[i]].second=i;
            }
            else
            {
                mp[s[i]]={1,i};
            }
        }
        int ans=INT_MAX;
        for(auto it:mp)
        {
            if(it.second.first==1)
                ans=min(ans,it.second.second);
        }
        if(ans==INT_MAX)
            return -1;
        return ans;
    }