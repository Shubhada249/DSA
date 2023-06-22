//https://leetcode.com/problems/jump-game-ii/


//O(n^2)  //SC:O(n)
int fun(int ind,int n,vector<int>& nums,vector<int> &dp)
    {
        if(ind==n-1)
            return dp[ind]=0;
        else if(nums[ind]==0)
            return dp[ind]=INT_MAX;
        if(dp[ind]!=-1)
            return dp[ind];
        else
        {
            int mini=INT_MAX;
            for(int i=1;i<=nums[ind] && ind+i<n;i++)
            {
                mini=min(fun(ind+i,n,nums,dp),mini);
            }
            if(mini==INT_MAX)
                return dp[ind]=mini;
            else
                return dp[ind]=mini+1;
        }
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        //return fun(0,n,nums,dp);
        for(int ind=n-1;ind>=0;ind--)
        {
            if(ind==n-1)
                dp[ind]=0;
            else if(nums[ind]==0)
                dp[ind]=INT_MAX;
            else
            {
                int mini=INT_MAX;
                for(int i=1;i<=nums[ind] && ind+i<n;i++)
                {
                    mini=min(dp[ind+i],mini);
                }
                if(mini==INT_MAX)
                {
                    dp[ind]=mini;
                }
                else
                    dp[ind]=mini+1;
            }
        }
        return dp[0];
    }


//O(n)  //SC:O(1)
int jump(vector<int>& nums) {
        int n=nums.size(),end=0,far=0,jump=0;
        for(int i=0;i<n-1;i++)
        {
            far=max(far,i+nums[i]);
            if(i==end)
            {
                jump++;
                end=far;
            }
        }
        return jump;
    }