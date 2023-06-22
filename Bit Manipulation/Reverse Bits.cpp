//https://leetcode.com/problems/reverse-bits/

//TC:O(1)   //SC:O(1)
uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        int cnt=0;
        while(cnt!=32)
        {
            ans=(ans<<1)+(n&1);
            n=n>>1;
            cnt++;
        }
        return ans;
    }