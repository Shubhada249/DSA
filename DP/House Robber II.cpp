//https://leetcode.com/problems/house-robber-ii/

//Edge Case:    1.nums size is 1
int fun(int n,vector<int>& nums,vector<int> &dp)
{
    if(n==0)
        return dp[n]=0;
    else if(n==1)
        return dp[n]=nums[0];
    if(dp[n]!=-1)
        return dp[n];
    else
        return dp[n]=max(nums[n-1]+fun(n-2,nums,dp),fun(n-1,nums,dp));
}
int rob(vector<int>& nums) {
    int n=nums.size();
    if(n==1)
        return nums[n-1];
    vector<int> dp1(n,-1);
    //int a=fun(n-1,nums,dp1);
    for(int i=0;i<n;i++)
    {
        if(i==0)
                dp1[i]=0;
        else if(i==1)
                dp1[i]=nums[0];
        else
                dp1[i]=max(nums[i-1]+dp1[i-2],dp1[i-1]);
    }
    nums[0]=0;
    vector<int> dp2(n+1,-1);
    //int b=fun(n,nums,dp2);
    for(int i=0;i<n+1;i++)
    {
        if(i==0)
                dp2[i]=0;
        else if(i==1)
                dp2[i]=nums[0];
        else
                dp2[i]=max(nums[i-1]+dp2[i-2],dp2[i-1]);
    }
    return max(dp1[n-1],dp2[n]);
}