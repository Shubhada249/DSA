//https://leetcode.com/problems/house-robber/
int fun(int n,vector<int>& nums,vector<int> &dp)
{
    if(n==0)
        return dp[n]=0;
    if(n==1)
        return dp[n]=nums[0];
    if(dp[n]!=-1)
        return dp[n];
    else
        return dp[n]=max(nums[n-1]+fun(n-2,nums,dp),fun(n-1,nums,dp));
}
int rob(vector<int>& nums) {
    int n=nums.size();
    vector<int> dp(n+1,-1);
    //return fun(n,nums,dp);
    for(int i=0;i<n+1;i++)
    {
        if(i==0)
            dp[i]= 0;
        else if(i==1)
            dp[i]= nums[0];
        else
            dp[i]=max(nums[i-1]+dp[i-2],dp[i-1]);
    }
    return dp[n];
}