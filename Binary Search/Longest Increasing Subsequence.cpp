//https://leetcode.com/problems/longest-increasing-subsequence/

//TC:O(n^2)     //SC:O(n^2)
int fun(int n,int prev,vector<int>& nums,vector<vector<int>> &dp)
{
    if(n==0)
        return dp[n][prev]=0;
    if(dp[n][prev]!=-1)
        return dp[n][prev];
    else if(prev==0 || nums[prev-1]>nums[n-1])
        return dp[n][prev]=max(1+fun(n-1,n,nums,dp),fun(n-1,prev,nums,dp));
    else
        return dp[n][prev]=fun(n-1,prev,nums,dp);
}
int lengthOfLIS(vector<int>& nums) {
    int n=nums.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    //return fun(n,0,nums,dp);
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0)
                dp[i][j]=0;
            else if(j==0 || nums[j-1]>nums[i-1])
                dp[i][j]=max(1+dp[i-1][i],dp[i-1][j]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][0];
}

//TC:O(n log n)     //SC:O(1)
int lengthOfLIS(vector<int>& nums) {
    int n=nums.size();
    vector<int> tail;
    for(int i=0;i<n;i++)
    {
        if(tail.empty() || tail[tail.size()-1]<nums[i])
            tail.push_back(nums[i]);
        else
        {
            auto it=lower_bound(tail.begin(),tail.end(),nums[i]);
            int ceil_ind=it-tail.begin();
            tail[ceil_ind]=nums[i];
        }
    }
    return tail.size();
}