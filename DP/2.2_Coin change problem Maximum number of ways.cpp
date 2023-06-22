//https://practice.geeksforgeeks.org/problems/coin-change2448/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

long long int fun(int n,int sum,int coins[],vector<vector<long long int>> &dp)
{
    if(n==0)
    {
        if(sum==0)
            return dp[n][sum]=1;
        else 
            return dp[n][sum]=0;
    }
    if(dp[n][sum]!=-1)
        return dp[n][sum];
    else if(coins[n-1]<=sum)
        return dp[n][sum]=fun(n,sum-coins[n-1],coins,dp)+fun(n-1,sum,coins,dp);
    else
        return dp[n][sum]=fun(n-1,sum,coins,dp);
}
long long int count(int coins[], int N, int sum) {
    // code here.
    vector<vector<long long int>> dp(N+1,vector<long long int>(sum+1,-1));
    //return fun(N,sum,coins,dp);
    for(int i=0;i<N+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)
            {
                if(j==0)
                    dp[i][j]=1;
                else 
                    dp[i][j]=0;
            }
            else if(coins[i-1]<=j)
                dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[N][sum];
}