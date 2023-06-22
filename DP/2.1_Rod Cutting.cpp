//https://practice.geeksforgeeks.org/problems/rod-cutting0840/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

int fun(int n,int w,int price[],vector<vector<int>> &dp)
{
    if(w==0 || n==0)
        return dp[n][w]=0;
    if(dp[n][w]!=-1)
        return dp[n][w];
    else if(n<=w)
        return dp[n][w]=max(price[n-1]+fun(n,w-n,price,dp),fun(n-1,w,price,dp));
    else 
        return dp[n][w]=fun(n-1,w,price,dp);
}
int cutRod(int price[], int n) {
    //code here
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    //return fun(n,n,price,dp);
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(j==0 || i==0)
                dp[i][j]=0;
            else if(i<=j)
                dp[i][j]=max(price[i-1]+dp[i][j-i],dp[i-1][j]);
            else 
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][n];
}