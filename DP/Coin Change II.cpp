//https://leetcode.com/problems/coin-change-ii/

//TC:O(n*amount)    //SC:O(n*amount)
int fun(int n,int amt, vector<int>& coins,vector<vector<int>> &dp)
    {
        if(dp[n][amt]!=-1)
            return dp[n][amt];
        if(n==0)
        {
            if(amt==0)
                return dp[n][amt]=1;
            else
                return dp[n][amt]=0;
        }
        if(amt==0)
            return dp[n][amt]=1;
        int a=0,b=0;
        if(coins[n-1]<=amt)
            a=fun(n,amt-coins[n-1],coins,dp);
        b=fun(n-1,amt,coins,dp);
        return dp[n][amt]=a+b;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        //return fun(n,amount,coins,dp);
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                if(i==0)
                {
                    if(j==0)
                        dp[i][j]=1;
                    else
                        dp[i][j]=0;
                }
                else if(j==0)
                    dp[i][j]=1;
                else
                {
                    int a=0,b=0;
                    if(coins[i-1]<=j)
                        a=dp[i][j-coins[i-1]];
                    b=dp[i-1][j];
                    dp[i][j]=a+b;
                }
            }
        }
        return dp[n][amount];
    }