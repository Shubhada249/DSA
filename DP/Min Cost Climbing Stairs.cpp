//https://leetcode.com/problems/min-cost-climbing-stairs/

int fun(int n,vector<int>& cost,vector<int> &dp)
    {
        if(n==0 || n==1)
            return dp[n]=0;
        if(dp[n]!=-1)
            return dp[n];
        else
            return dp[n]=min(cost[n-1]+fun(n-1,cost,dp),cost[n-2]+fun(n-2,cost,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        //return fun(n,cost,dp);
        for(int i=0;i<n+1;i++)
        {
            if(i==0 || i==1)
                dp[i]=0;
            else
                dp[i]=min(cost[i-1]+dp[i-1],cost[i-2]+dp[i-2]);
        }
        return dp[n];
    }