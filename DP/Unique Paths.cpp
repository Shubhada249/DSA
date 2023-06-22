//https://leetcode.com/problems/unique-paths/

int fun(int m,int n,vector<vector<int>> &dp)
    {
        if(m==0 || n==0)
            return dp[m][n]=0;
        else if(m==1 && n==1)
            return dp[m][n]=1;
        if(dp[m][n]!=-1)
            return dp[m][n];
        else 
            return dp[m][n]=fun(m-1,n,dp)+fun(m,n-1,dp);
        
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        //return fun(m,n,dp);
        for(int i=0;i<m+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=0;
                else if(i==1 && j==1)
                    dp[i][j]=1;
                else 
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m][n];
    }
