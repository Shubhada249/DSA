//https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions4610/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

int minDeletions(string str, int n) { 
    //complete the function here 
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    string str1=str;
    reverse(str1.begin(),str1.end());
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(str[i-1]==str1[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return n-dp[n][n];
} 