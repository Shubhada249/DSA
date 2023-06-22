int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n=str.size();
		    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
		    string str1=str;
		    for(int i=0;i<n+1;i++)
		    {
		        for(int j=0;j<n+1;j++)
		        {
		            if(i==0 || j==0)
		                dp[i][j]=0;
		            else if(str[i-1]==str1[j-1] && i!=j)
		                dp[i][j]=1+dp[i-1][j-1];
		            else
		                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		        }
		    }
		    return dp[n][n];
		}