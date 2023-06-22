//https://leetcode.com/problems/is-subsequence/

//TC:O(mn)    //SC:O(mn)
int fun(int m,int n,string &s,string &t,vector<vector<int>> &dp)
    {
        if(m==0 || n==0)
            return dp[m][n]=0;
        if(dp[m][n]!=-1)
            return dp[m][n];
        if(s[m-1]==t[n-1])
            return dp[m][n]=1+fun(m-1,n-1,s,t,dp);
        else
            return dp[m][n]=max(fun(m,n-1,s,t,dp),fun(m-1,n,s,t,dp));
    }
    bool isSubsequence(string s, string t) {
        int m=s.size(),n=t.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));        
        return m==fun(m,n,s,t,dp);        
    }


//TC:O(m+n)     //SC:O(1)
bool isSubsequence(string s, string t) {
        int m=s.size(),n=t.size();
        int i=0,j=0;
        while(i<m && j<n)
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
                j++;
        }
        if(i==m)
            return true;
        else
            return false;
    }