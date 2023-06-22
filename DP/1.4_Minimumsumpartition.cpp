//https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1

int minDifference(int arr[], int n)  { 
	    // Your code goes here    
	int total=accumulate(arr,arr+n,0);
	int range=total/2;
	vector<vector<int>> dp(n+1,vector<int>(range+1,-1));

	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<range+1;j++)
		{
			if(i==0)
			{
				if(j==0)
					dp[i][j]=true;
				else
					dp[i][j]=false;
			}
			else if(j==0)
				dp[i][j]=true;
				
			else if(arr[i-1]<=j)
				dp[i][j]=(dp[i-1][j-arr[i-1]] || dp[i-1][j]);
			
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	
	vector<int> possibleS1;
	for(int j=0;j<range+1;j++)
	{
		if(dp[n][j]==true)
		{
			possibleS1.push_back(j);
		}
	}
	int mini=INT_MAX;
	for(int i=0;i<possibleS1.size();i++)
	{
		mini=min(mini,total-(2*possibleS1[i]));
	}
	return mini;
} 