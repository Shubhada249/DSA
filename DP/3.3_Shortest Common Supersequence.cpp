//https://leetcode.com/problems/shortest-common-supersequence/
int fun(int n,int m,string &str1,string &str2,vector<vector<int>> &dp)
    {
        if(n==0 || m==0)
            return dp[n][m]=0;
        if(dp[n][m]!=-1)
            return dp[n][m];
        if(str1[n-1]==str2[m-1])
            return dp[n][m]=1+fun(n-1,m-1,str1,str2,dp);
        else
            return dp[n][m]=max(fun(n-1,m,str1,str2,dp),fun(n,m-1,str1,str2,dp));
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size(),m=str2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int a= fun(n,m,str1,str2,dp);
        
        
        string ans="";
        int i=n,j=m;
        while(i>0 && j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                ans.push_back(str1[i-1]);
                i--;
                j--;
            }
            else
            {
                if(dp[i-1][j]>dp[i][j-1])
                {
                    ans.push_back(str1[i-1]);
                    i--;
                }
                else
                {
                    ans.push_back(str2[j-1]);
                    j--;
                }
            }
        }
        while(j!=0)
        {
            ans.push_back(str2[j-1]);
            j--;
        }
        while(i!=0)
        {
            ans.push_back(str1[i-1]);
            i--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }