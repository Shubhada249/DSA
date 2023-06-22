//https://leetcode.com/problems/power-of-four/


//TC:O(32)  //SC:O(1)
bool isPowerOfFour(int n) {
        if(n<=0)
            return false;
        int cnt=0,nn=n;
        while(n)
        {
            cnt++;
            n=n>>1;
        }
        if((cnt-1)%2==0 && (nn&(nn-1))==0)
            return true;
        return false;
    }

//TC:O(1)  //SC:O(1)
bool isPowerOfFour(int n) {
        if(n>0 && (n&(n-1))==0 && (n-1)%3==0)
            return true;
        return false;

    }