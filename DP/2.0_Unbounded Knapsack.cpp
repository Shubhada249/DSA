//https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

int fun(int n,int w,int val[], int wt[],vector<vector<int>> &dp)
{
    if(n==0 || w==0)
    {
            return dp[n][w]=0;  
    }
    if(dp[n][w]!=-1)
        return dp[n][w];
    else if(wt[n-1]<=w)
    {
        return dp[n][w]=max(val[n-1]+fun(n,w-wt[n-1],val,wt,dp),fun(n-1,w,val,wt,dp));
    }
    else
    {
        return dp[n][w]=fun(n-1,w,val,wt,dp);
    }
}
int knapSack(int n, int w, int val[], int wt[])
{
    // code here
    vector<vector<int>> dp(n+1,vector<int>(w+1,-1));
    //return fun(N,W,val,wt,dp);
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<w+1;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;  
            }
            else if(wt[i-1]<=j)
            {
                dp[i][j]=max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}