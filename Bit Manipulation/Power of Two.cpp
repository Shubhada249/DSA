//https://leetcode.com/problems/power-of-two/

////TC:O(1)   //SC:O(1)
bool isPowerOfTwo(int n) {
        if(n<=0)
            return false;
        double a=log10(n)/log10(2);
        int b=(int)a;
        if(a==b)
            return true;
        return false;
    }

//TC:O(1)   //SC:O(1)
bool isPowerOfTwo(int n) {
        if(n<=0)
            return false;
        if((n & n-1)==0)
            return true;
        return false;
    }