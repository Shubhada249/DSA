//https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1

//Note:Grow Tree till end
int fun(int n,int sum,int arr[],vector<vector<int>> &dp)
	{
	    if(n==0)
	    {
	        if(sum==0)
	            return dp[n][sum]=1;
	       else
	           return dp[n][sum]=0;
	    }

	    if(dp[n][sum]!=-1)
	        return dp[n][sum];
	   
	    else if(arr[n-1]<=sum)
	    {
	        return dp[n][sum]=((fun(n-1,sum-arr[n-1],arr,dp)%1000000007)+(fun(n-1,sum,arr,dp)%1000000007))%1000000007;
	    }
	    else
	        return dp[n][sum]=fun(n-1,sum,arr,dp)%1000000007;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        //return fun(n,sum,arr,dp)%1000000007;
    
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
        	    else if(arr[i-1]<=j)
        	    {
        	        dp[i][j]=((dp[i-1][j-arr[i-1]]%1000000007)+(dp[i-1][j]%1000000007))%1000000007;
        	    }
        	    else
        	        dp[i][j]=dp[i-1][j]%1000000007;
            }
        }
        
        return dp[n][sum]%1000000007;
        
	}