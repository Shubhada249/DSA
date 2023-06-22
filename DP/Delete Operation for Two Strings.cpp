//https://leetcode.com/problems/delete-operation-for-two-strings/


int fun(int m,int n,string &word1, string &word2,vector<vector<int>> &dp)
    {
        if(m==0 || n==0)
            return dp[m][n]=0;
        if(dp[m][n]!=-1)
            return dp[m][n];
        if(word1[m-1]==word2[n-1])
            return dp[m][n]=1+fun(m-1,n-1,word1,word2,dp);
        else
            return dp[m][n]=max(fun(m-1,n,word1,word2,dp),fun(m,n-1,word1,word2,dp));
    }
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        //int lcs=fun(m,n,word1,word2,dp);
        for(int i=0;i<m+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=0;
                else if(word1[i-1]==word2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int lcs=dp[m][n];
        return m+n-(2*lcs);
    }