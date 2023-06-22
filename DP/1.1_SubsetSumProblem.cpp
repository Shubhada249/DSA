//https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

bool fun(int n,int sum,vector<int>arr,vector<vector<int>> &dp)
    {
        if(n==0)
        {
            if(sum==0)
                return dp[n][sum]=true;
            else
                return dp[n][sum]=false;
        }
        if(sum==0)
            return dp[n][sum]=true;
        
        if(dp[n][sum]!=-1)
            return dp[n][sum];
        if(arr[n-1]<=sum)
            return dp[n][sum]=(fun(n-1,sum-arr[n-1],arr,dp)||fun(n-1,sum,arr,dp));
        else
            return dp[n][sum]=fun(n-1,sum,arr,dp);
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
       // return fun(n,sum,arr,dp);
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
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
                    
                else if(arr[i-1]<=j)
                    dp[i][j]=(dp[i-1][j-arr[i-1]]||dp[i-1][j]);
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][sum];
    }