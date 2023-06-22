//https://leetcode.com/problems/fibonacci-number/

//TC:O(2^n)//SC:O(n)
int fib(int n) {
        if(n<=1)
            return n;
        return fib(n-1)+fib(n-2);
    }


//TC:O(n)//SC:O(2n)
int fun(int n,vector<int> &dp)
    {
        if(dp[n]!=-1)
            return dp[n];
        if(n<=1)
            return dp[n]=n;
        return dp[n]=fun(n-1,dp)+fun(n-2,dp);
    }
    int fib(int n) {
        vector<int> dp(n+1,-1);
        return fun(n,dp);
    }


//TC:O(n)//SC:O(n)
int fib(int n) {
        vector<int> dp(n+1,-1);
        dp[0]=0;
        if(n==0)
            return dp[n];
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }

//TC:O(n)//SC:O(1)
int fib(int n) {
        int p1=0,p2=1;
        if(n==p1 || n==p2)
            return n;
        int ans=0;
        for(int i=2;i<=n;i++)
        {
            ans=p1+p2;
            p1=p2;
            p2=ans;
        }
        return ans;
    }