//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

int fun(int ind,int bl,vector<int>& prices,int n,vector<vector<int>> &dp)
{
    if(ind>=n)
        return dp[ind][bl]=0;
    if(dp[ind][bl]!=-1)
        return dp[ind][bl];
    else if(bl)
    {
        return dp[ind][bl]=max(-prices[ind]+fun(ind+1,0,prices,n,dp),fun(ind+1,1,prices,n,dp));
    }
    else
    {
        return dp[ind][bl]=max(prices[ind]+fun(ind+2,1,prices,n,dp),fun(ind+1,0,prices,n,dp));
    }
}
int maxProfit(vector<int>& prices) {
    int n=prices.size();
    vector<vector<int>> dp(n+2,vector<int>(2,-1));
    //return fun(0,1,prices,n,dp);
    for(int ind=n+1;ind>=0;ind--)
    {
        for(int bl=0;bl<2;bl++)
        {
            if(ind>=n)
                dp[ind][bl]=0;
            else if(bl)
            {
                dp[ind][bl]=max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
            }
            else
            {
                dp[ind][bl]=max(prices[ind]+dp[ind+2][1],dp[ind+1][0]);
            }
        }
    }
    return dp[0][1];
}