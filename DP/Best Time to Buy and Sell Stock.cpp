//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

//TC:O(n)   SC:O(n)
int maxProfit(vector<int>& prices) {
    int n=prices.size();
    vector<int> dp(n,0);
    int max_profit=0;
    
    for(int i=n-2;i>=0;i--)
    {
        dp[i]=max(dp[i+1],prices[i+1]);
        max_profit=max(max_profit,dp[i]-prices[i]);
    }
    return max_profit;
}

//TC:O(n)   SC:O(1)
int maxProfit(vector<int>& prices) {
    int n=prices.size();
    int maxi=0,max_profit=0;
    
    for(int i=n-2;i>=0;i--)
    {
        maxi=max(maxi,prices[i+1]);
        max_profit=max(max_profit,maxi-prices[i]);
    }
    return max_profit;
}