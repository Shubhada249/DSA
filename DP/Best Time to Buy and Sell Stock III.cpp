//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

int fun(int ind,int bl,int t,vector<int>& prices,int n,vector<vector<vector<int>>> &dp)
{
    if(ind==n || t<=0)
        return dp[ind][bl][t]=0;
    if(dp[ind][bl][t]!=-1)
        return dp[ind][bl][t];
    else if(bl)
    {
        return dp[ind][bl][t]=max(-prices[ind]+fun(ind+1,0,t,prices,n,dp),fun(ind+1,1,t,prices,n,dp));
    }
    else
    {
        return dp[ind][bl][t]=max(prices[ind]+fun(ind+1,1,t-1,prices,n,dp),fun(ind+1,0,t,prices,n,dp));
    }
}
int maxProfit(vector<int>& prices) {
    int n=prices.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
    //return fun(0,1,2,prices,n,dp);
    for(int ind=n;ind>=0;ind--)
    {
        for(int bl=0;bl<2;bl++)
        {
            for(int t=0;t<=2;t++)
            {
                if(ind==n || t<=0)
                    dp[ind][bl][t]=0;
                else if(bl)
                {
                    dp[ind][bl][t]=max(-prices[ind]+dp[ind+1][0][t],dp[ind+1][1][t]);
                }
                else
                {
                    dp[ind][bl][t]=max(prices[ind]+dp[ind+1][1][t-1],dp[ind+1][0][t]);
                }
            }
        }
    }
    return dp[0][1][2];
}