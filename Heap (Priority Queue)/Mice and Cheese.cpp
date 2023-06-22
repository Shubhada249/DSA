//https://leetcode.com/problems/mice-and-cheese/


//TC:O(n^2)    //SC:O(n^2)
    int fun(int n,int k,vector<int>& r1, vector<int>& r2,vector<vector<int>> &dp,vector<int> &ps)
    {
        
        if(n==0 && k==0)
            return dp[n][k]=0;
        else if(k==0)
        {
            // int sum=0;
            // while(n!=0)
            // {
            //     sum+=r2[n-1];
            //     n--;
            // }
            return dp[n][k]=ps[n-1];
        }
        else if(n==0 && k!=0)
            return dp[n][k]=INT_MIN;
        if(dp[n][k]!=-1)
            return dp[n][k];
        
        else 
            return dp[n][k]=max(r1[n-1]+fun(n-1,k-1,r1,r2,dp,ps),r2[n-1]+fun(n-1,k,r1,r2,dp,ps));
    }
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n=reward1.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        vector<int> ps(n,0);
        ps[0]=reward2[0];
        for(int i=1;i<n;i++)
        {
            ps[i]=ps[i-1]+reward2[i];
        }
//        return fun(n,k,reward1,reward2,dp,ps);
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<k+1;j++)
            {
                if(i==0 && j==0)
                    dp[i][j]=0;
                else if(j==0)
                {
                    
                    dp[i][j]=ps[i-1];
                }
                else if(i==0 && j!=0)
                    dp[i][j]=INT_MIN;

                else 
                    dp[i][j]=max(reward1[i-1]+dp[i-1][j-1],reward2[i-1]+dp[i-1][j]);
            }
        }
        return dp[n][k];
    }


//TC:O(n)    //SC:O(k)
int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n=reward1.size();
        
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++)
        {
            if(pq.size()<k)
                pq.push(reward1[i]-reward2[i]);
            else
            {
                if(!pq.empty() && reward1[i]-reward2[i] > pq.top())
                {
                    pq.pop();
                    pq.push(reward1[i]-reward2[i]);
                }
            }
        }
        
        int ans=0;
        while(!pq.empty())
        {
            ans+=pq.top();
            pq.pop();
        }
        ans+=accumulate(reward2.begin(),reward2.end(),0);
        return ans;
    }