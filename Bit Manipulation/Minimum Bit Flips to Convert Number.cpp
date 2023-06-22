//https://leetcode.com/problems/minimum-bit-flips-to-convert-number/

//TC:O(32)  //SC:O(1)
int minBitFlips(int start, int goal) {
        int sg=start^goal,ans=0;
        while(sg)
        {
            if((sg & 1)==1)
                ans++;
            sg=sg>>1;
        }
        return ans;
    }