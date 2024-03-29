//https://leetcode.com/problems/minimum-cost-to-make-all-characters-equal/

//TC:O(n)   //SC:O(1)
long long minimumCost(string s) {
        int n=s.size();
        long long ans=0;
        for(int i=1;i<n;i++)
        {
            if(s[i]!=s[i-1])
                ans+=min(i,n-i);
        }
        return ans;
    }