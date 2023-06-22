//https://leetcode.com/problems/jump-game-vi/

//TC:O(n)   //SC:O(n+k)
int fun(int start,int n,int k,vector<int>& nums,vector<int> &dp)
    {
        if(dp[start]!=-1)
            return dp[start];
        if(start==n-1)
            return dp[start]=nums[start];
        
        int maxi=INT_MIN;
        for(int i=start+1;i<=start+k && i<n;i++)
        {
            maxi=max(maxi,fun(i,n,k,nums,dp));
        }
        return dp[start]=maxi+nums[start];
    }
    int maxResult(vector<int>& nums, int k) {
       // nums.insert(nums.begin(),0);
        int n=nums.size();
        vector<int> dp(n,-1);
        //return fun(0,n,k,nums,dp);
        deque<int> dq;
        int i=n-1;
        for(int start=n-1;start>=0;start--)
        {
            if(start==n-1)
            {
                dp[start]=nums[start];
                dq.push_back(dp[start]);
            }
            else
            {
                // int maxi=INT_MIN;
                // for(int i=start+1;i<=start+k && i<n;i++)
                // {
                //     maxi=max(maxi,dp[i]);
                // } 
                
                int maxi=dq.front();
                dp[start]=maxi+nums[start];
                if(dp[start]>dq.back())
                {
                    while(!dq.empty() && dq.back()<dp[start])
                        dq.pop_back();
                    dq.push_back(dp[start]);
                }
                else
                {
                    dq.push_back(dp[start]);
                }
                
                if(i-start+1>k )
                {
                    if(dq.front()==dp[i])
                        dq.pop_front();
                    i--;
                }
            }
        }
        return dp[0];
    }