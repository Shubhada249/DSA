//https://leetcode.com/problems/number-of-people-aware-of-a-secret/

//TC:O(n)   //SC:O(n)
int fun(int k,int n, int d, int f,vector<int> &dp)
    {
        if(dp[k]!=-1)
            return dp[k];
        int total=0;
        for(int i=k+d;i<=k+f-1 && i<=n;i++)
        {
            total=(total%mod+1)%mod;
            total=(total+fun(i,n,d,f,dp))%mod;
        }
        if(k+f<=n)
            total--;
        return dp[k]=total;
    }
    int peopleAwareOfSecret(int n, int d, int f) {
        vector<int> dp(n+1,-1);
        //return (1+fun(1,n,delay,forget,dp))%mod;
        int p=n;
        long long sum=0;
        unordered_map<int,long long> mp;
        for(int k=n;k>=1;k--)
        {
            int total=0;
            // for(int i=k+d;i<=k+f-1 && i<=n;i++)
            // {
            //     total=(total%mod+1)%mod;
            //     total=(total+dp[i])%mod;
            // }
            if((min(n,k+f-1)-k-d+1)>=0)
                total= (total+(min(n,k+f-1)-k-d+1)%mod)%mod;
            if(k+d<=n)
                total=(total+ mp[k+d]%mod)%mod;
            if(k+f<=n)
                total--;
            dp[k]=total;
            
            sum=(sum+dp[k]);
            mp[k]=sum;
            if(p-k+1==f-d)
            {
                sum-=dp[p];
                p--;
            }                            
        }
        // for(auto it:mp)
        //     cout<<it.first<<" "<<it.second<<"\n";
        return (dp[1]+1)%mod;
    }