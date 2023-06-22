//https://leetcode.com/problems/factorial-trailing-zeroes/

//TC:O(log 5 n)     //SC:O(1)
int trailingZeroes(int n) {
        int ans=0;
        for(int i=5;i<=n;i=i*5)
        {
            ans+=(n/i);
        }
        return ans;
    }