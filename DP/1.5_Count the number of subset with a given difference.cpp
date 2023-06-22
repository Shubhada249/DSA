//https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628?leftPanelTab=0

#include <bits/stdc++.h> 
#define mod 1000000007

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int total=accumulate(arr.begin(),arr.end(),0);
    if((total+d)%2!=0 )
        return 0;
    else
    {
        int sum=(total+d)/2;
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(i==0)
                {
                    if(j==0)
                        dp[i][j]=1;
                    else
                        dp[i][j]=0;
                }
                else if(arr[i-1]<=j)
                    dp[i][j]=((dp[i-1][j-arr[i-1]])%mod+(dp[i-1][j])%mod)%mod;
                else
                    dp[i][j]=dp[i-1][j]%mod;
            }
        }
        return dp[n][sum];
    }
}


