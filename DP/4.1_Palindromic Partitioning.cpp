//https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
bool ispalindrome(int i,int j,string &str)
    {
        // string st=str;
        // reverse(st.begin(),st.end());
        // return st==str;
        for(;i<j;i++,j--)
        {
            if(str[i]!=str[j])
                return false;
        }
        return true;
    }
    int fun(int i,int j,string &str,vector<vector<int>> & dp)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i==j || ispalindrome(i,j,str))
            return dp[i][j]=0;
        
        int ans=INT_MAX; 
        for(int k=i;k<j;k++)
        {
            int temp=fun(i,k,str,dp)+fun(k+1,j,str,dp)+1;
            ans=min(ans,temp);
        }
        return dp[i][j]=ans;
    }
    int palindromicPartition(string str)
    {
        // code here
        int i=0,n=str.size(),j=n-1;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        //return fun(i,j,str,dp);
        vector<vector<bool>> pal(n,vector<bool>(n,true));
        for(i=n-1;i>=0;i--)
        {
            for(j=i;j<n;j++)
            {
                if(i==j || (j-i+1>2 && str[i]==str[j] && pal[i+1][j-1]) || (j-i+1==2 && str[i]==str[j]))
                {
                    dp[i][j]=0;
                    pal[i][j]=true;
                }
                else
                {
                    pal[i][j]=false;
                    int ans=INT_MAX; 
                    for(int k=i;k<j;k++)
                    {
                        int temp=dp[i][k]+dp[k+1][j]+1;
                        ans=min(ans,temp);
                    }
                    dp[i][j]=ans;
                }
            }
        }
        return dp[0][n-1];
    }