 //https://leetcode.com/problems/partition-equal-subset-sum/

 bool fun(int n,int sum,vector<int>& nums,vector<vector<int>> &dp)
    {
        if(n==0)
        {
            if(sum==0)
                return dp[n][sum]=true;
            else 
                return dp[n][sum]=false;
        }
        else if(sum==0)
            return dp[n][sum]=true;
        if(dp[n][sum]!=-1)
            return dp[n][sum];
        else if(nums[n-1]<=sum)
            return dp[n][sum]=(fun(n-1,sum-nums[n-1],nums,dp)||fun(n-1,sum,nums,dp));
        else 
            return dp[n][sum]=fun(n-1,sum,nums,dp);
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0)
            return false;
        else
        {
            vector<vector<int>> dp(nums.size()+1,vector<int>(sum/2+1,-1));
            //return fun(nums.size(),sum/2,nums,dp);
            for(int i=0;i<nums.size()+1;i++)
            {
                for(int j=0;j<sum/2+1;j++)
                {
                    if(i==0)
                    {
                        if(j==0)
                            dp[i][j]=true;
                        else 
                            dp[i][j]=false;
                    }
                    else if(j==0)
                        dp[i][j]=true;
                    else if(nums[i-1]<=j)
                        dp[i][j]=(dp[i-1][j-nums[i-1]]||dp[i-1][j]);
                    else 
                        dp[i][j]=dp[i-1][j];
                }
            }
            int n=nums.size();
            return dp[n][sum/2];
        }
    }