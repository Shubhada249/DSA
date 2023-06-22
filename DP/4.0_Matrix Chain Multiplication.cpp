//https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

int fun(int i,int j,int arr[],vector<vector<int>> &dp)
    {
        if(i==j)
            return dp[i][j]=0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<j;k++)
        {
            int temp=fun(i,k,arr,dp)+fun(k+1,j,arr,dp)+(arr[i]*arr[j+1]*arr[k+1]);
            ans=min(ans,temp);
        }
        return dp[i][j]=ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N-1,vector<int>(N-1,-1));
        //return fun(0,N-2,arr,dp);
        for(int i=N-2;i>=0;i--)
        {
            for(int j=i;j<N-1;j++)
            {
                if(i==j)
                    dp[i][j]=0;
                else
                {
                    int ans=INT_MAX;
                    for(int k=i;k<j;k++)
                    {
                        int temp=dp[i][k]+dp[k+1][j]+(arr[i]*arr[j+1]*arr[k+1]);
                        ans=min(ans,temp);
                    }
                    dp[i][j]=ans;
                }
            }
        }
        return dp[0][N-2];
    }