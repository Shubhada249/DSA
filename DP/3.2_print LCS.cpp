//https://www.geeksforgeeks.org/printing-longest-common-subsequence/

int fun(int n,int m,string &text1, string &text2,vector<vector<int>> &dp)
    {
        if(n==0 || m==0)
            return dp[n][m]=0;
        if(dp[n][m]!=-1)
            return dp[n][m];
        if(text1[n-1]==text2[m-1])
            return dp[n][m]=1+fun(n-1,m-1,text1,text2,dp);
        else
            return dp[n][m]=max(fun(n,m-1,text1,text2,dp),fun(n-1,m,text1,text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        //return fun(n,m,text1,text2,dp);
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<m+1;j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=0;
      
                else if(text1[i-1]==text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                
                else
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        
        string lcs="";
        int i=n,j=m;
        while(i>0 && j>0)
        {
            if(text1[i-1]==text2[j-1])
            {
                lcs.push_back(text1[i-1]);
                i--;
                j--;
            }
            else
            {
                if(dp[i][j-1]>dp[i-1][j])
                    j--;
                else
                    i--;
            }
        }
        reverse(lcs.begin(),lcs.end());
        cout<<lcs<<"\n";
        return dp[n][m];
    }