//https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

int fun(int w, int wt[], int val[], int n,vector<vector<int>> &dp) 
    { 
       // Your code here
        if(n==0 || w==0)
            return dp[n][w]=0;
        if(dp[n][w]!=-1)
            return dp[n][w];
        if(wt[n-1]<=w)
            return dp[n][w]=max(val[n-1]+fun(w-wt[n-1],wt,val,n-1,dp),fun(w,wt,val,n-1,dp));
        else
            return dp[n][w]=fun(w,wt,val,n-1,dp);
    }
    int knapSack(int w, int wt[], int val[], int n)
    {
        vector<vector<int>> dp(n+1,vector<int>(w+1,-1));
        //return fun(w,wt,val,n,dp);
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<w+1;j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=0;
                else if(wt[i-1]<=j)
                    dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][w];
    }