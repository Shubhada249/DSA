//https://leetcode.com/problems/replace-the-substring-for-balanced-string/

//TC:O(n)   //SC:O(1)
int balancedString(string s) {
        unordered_map<char,int> mp;
        mp['Q']=0;
        mp['W']=0;
        mp['E']=0;
        mp['R']=0;
        int n=s.size(),req=n/4,count=0;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        for(auto it:mp)
        {
            if(it.second>req)
                mp[it.first]-=req;
            else
            {
                mp[it.first]=0;
                count++;
            }
        }
        if(count==4)
            return 0;
        int i=0,j=0,ans=INT_MAX;
        
        while(j<n)
        {
            mp[s[j]]--;
            if(mp[s[j]]==0)
                count++;
            
            if(count<4)
                j++;
            
            else if(count==4)
            {
                while(i<=j && j<n && count==4)
                {
                    ans=min(ans,j-i+1);
                    mp[s[i]]++;
                    if(mp[s[i]]==1)
                        count--;
                    i++;
                }
                j++;
            }
        }
        return ans;
    }