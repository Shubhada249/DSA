//https://leetcode.com/problems/hamming-distance/

//TC:O(32)  //SC:O(1)
int hammingDistance(int x, int y) {
        int axor=x^y;
        int ans=0;
        while(axor)
        {
            if((1 & axor)==1)
                ans++;
            axor=axor>>1;
        }
        return ans;
    }