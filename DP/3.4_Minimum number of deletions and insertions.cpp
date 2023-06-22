//https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1
int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int m=str1.size(),n=str2.size();
	    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
	    for(int i=0;i<m+1;i++)
	    {
	        for(int j=0;j<n+1;j++)
	        {
	            if(i==0 || j==0)
	                dp[i][j]=0;
	                
	            else if(str1[i-1]==str2[j-1])
	                dp[i][j]=1+dp[i-1][j-1];
	                
	            else
	                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	        }
	    }
	    return m+n-(2*dp[m][n]);
	} 