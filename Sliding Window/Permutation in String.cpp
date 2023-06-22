//https://leetcode.com/problems/permutation-in-string/
//TC:O(n)   //SC:O(1)
bool checkInclusion(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        unordered_map<char,int> mp;
        int i=0,j=0;
        for(int i=0;i<n1;i++)
        {
            mp[s1[i]]++;
        }
        int count=0;
        while(j<n2)
        {
            if(mp.find(s2[j])!=mp.end())
            {
                mp[s2[j]]--;
                if(mp[s2[j]]==0)
                    count++;
                else if(mp[s2[j]]==-1)
                    count--;
            }
            else 
            {
               // cout<<j<<" ";
                while(i<=j)
                {
                    if(mp.find(s2[i])!=mp.end())
                    {
                        mp[s2[i]]++;
                        if(mp[s2[i]]==1)
                            count--;
                        else if(mp[s2[i]]==0)
                            count++;                    
                    }
                    i++;
                }
                j++;
                continue;
            }
            
            if(j-i+1<n1)
                j++;
            
            else if(j-i+1==n1)
            {
                if(count==mp.size())
                    return true;
                if(mp.find(s2[i])!=mp.end())
                {
                    mp[s2[i]]++;
                    if(mp[s2[i]]==1)
                        count--;
                    else if(mp[s2[i]]==0)
                        count++;                    
                }
                i++;
                j++;
            }
            //cout<<i<<" "<<j<<"\n";
        }
        return false;
    }