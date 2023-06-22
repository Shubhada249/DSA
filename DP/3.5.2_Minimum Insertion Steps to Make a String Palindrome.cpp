//https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

//TC:O(n^2)     //SC:O(n^2)
    int fun(int m,int n,string &s,string &t,vector<vector<int>> &dp)
    {
        if(m==0 || n==0)
            return dp[m][n]=0;
        if(dp[m][n]!=-1)
            return dp[m][n];
        else if(s[m-1]==t[n-1])
            return dp[m][n]=1+fun(m-1,n-1,s,t,dp);
        else
            return dp[m][n]=max(fun(m-1,n,s,t,dp),fun(m,n-1,s,t,dp));
    }
    int minInsertions(string s) {
        int n=s.size();
        string t=s;
        reverse(t.begin(),t.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return n-fun(n,n,s,t,dp);
    }