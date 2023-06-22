//https://leetcode.com/problems/partition-array-for-maximum-sum/

//TC:O(n^3) //SC:O(2n^2)
int fun(int i,int j,vector<int>& arr,int s,vector<vector<int>> &dp,vector<vector<int>> &mx)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        else if(i==j)
            return dp[i][j]=arr[i];
        else if(j-i+1<=s)
            return dp[i][j]=mx[i][j]*(j-i+1);
        else
        {
            int ans=INT_MIN;
            for(int k=i;k<j;k++)
            {
                int temp=fun(i,k,arr,s,dp,mx)+fun(k+1,j,arr,s,dp,mx);
                ans=max(ans,temp); 
            }        
            return dp[i][j]=ans;
        }
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int i=0,n=arr.size(),j=n-1;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        vector<vector<int>> mx(n,vector<int>(n,-1));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(i==j)
                    mx[i][j]=arr[i];
                else
                    mx[i][j]=max(mx[i][j-1],arr[j]);
            }
        }
        //return fun(i,j,arr,k,dp,mx);
        int s=k;
        for(i=n-1;i>=0;i--)
        {
            for(j=i;j<n;j++)
            {
                if(i==j)
                    dp[i][j]=arr[i];
                else if(j-i+1<=s)
                    dp[i][j]=mx[i][j]*(j-i+1);
                else
                {
                    int ans=INT_MIN;
                    for(k=i;k<j;k++)
                    {
                        int temp=dp[i][k]+dp[k+1][j];
                        ans=max(ans,temp); 
                    }        
                    dp[i][j]=ans;
                }
            }
        }
        return dp[0][n-1];        
    }