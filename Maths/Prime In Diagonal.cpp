//https://leetcode.com/problems/prime-in-diagonal/

//TC:O(n^2)     //SC:O(1)
bool isPrime(int n)
    {
        if(n==1)
            return false;
        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
                return false;
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int n=nums.size(),ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(isPrime(nums[i][i]))
                ans=max(ans,nums[i][i]);
        }
        for(int i=0;i<n;i++)
        {
            if(isPrime(nums[i][n-i-1]))
                ans=max(ans,nums[i][n-i-1]);
        }
        if(ans==INT_MIN)
            return 0;
        return ans;
    }