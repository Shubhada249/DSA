//https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/

//TC:O(n^2)     //SC:O(26)
int longestSubstring(string s, int k) {
        int n=s.size(),ans=0;
        for(int i=0;i<n;i++)
        {
            unordered_map<char,int> mp;
            int count=0;
            for(int j=i;j<n;j++)
            {
                mp[s[j]]++;
                if(mp[s[j]]==k)
                    count++;
                if(count==mp.size())
                    ans=max(ans,j-i+1);
            }
        }
        return ans;
    }


//TC:O(n^2)     //SC:O(n+26)
int fun(int start,int end,int k,string s)
    {
        if(start>end)
            return 0;
        
        unordered_map<char,int> mp;
        for(int i=start;i<=end;i++)
        {
            mp[s[i]]++;
        }
        int mid;
        for(mid=start;mid<=end;mid++)
        {
            if(mp[s[mid]]<k)
                break;
        }
        if(mid==end+1)
            return end-start+1;
        return max(fun(start,mid-1,k,s),fun(mid+1,end,k,s));
    }
    int longestSubstring(string s, int k) {
        int n=s.size(),ans=0;
        
        return fun(0,n-1,k,s);
    }