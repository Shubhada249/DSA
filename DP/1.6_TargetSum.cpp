//https://leetcode.com/problems/target-sum/

int findTargetSumWays(vector<int>& nums, int target) {
        int total=accumulate(nums.begin(),nums.end(),0);
        if(total+target<0 || (total+target)%2!=0)
            return 0;
        int sum=(total+target)/2;
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int> (sum+1,-1));
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(i==0)
                {
                    if(j==0)
                        dp[i][j]=1;
                    else
                        dp[i][j]=0;
                }
                else if(nums[i-1]<=j)
                    dp[i][j]=dp[i-1][j-nums[i-1]]+dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][sum];
    }