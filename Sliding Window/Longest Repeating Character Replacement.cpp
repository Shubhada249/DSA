//https://leetcode.com/problems/longest-repeating-character-replacement/
//TC:O(n)   //SC:O(1)
int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int n=s.size(),maxi=INT_MIN,ans=0;
        int i=0,j=0;
        while(j<n)
        {
            mp[s[j]]++;
            maxi=max(maxi,mp[s[j]]);
            if(j-i+1-maxi<=k)
            {
                ans=max(ans,j-i+1);
                j++;
            }
            else
            {
                mp[s[i]]--;
                i++;                
                j++;
            }
        }
        return ans;
    }