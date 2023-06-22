//https://leetcode.com/problems/number-of-1-bits/


//TC:O(MSB) //SC:O(1)
int hammingWeight(uint32_t n) {
        int ans=0;
        while(n!=0)
        {
            if((n&1)==1)
                ans++;
            n=n>>1;
        }
        return ans;
    }

//TC:O(no. of set bits) //SC:O(1)
int hammingWeight(uint32_t n) {
        int ans=0;
        while(n!=0)
        {
            n=n&n-1;
            ans++;
        }
        return ans;
    }