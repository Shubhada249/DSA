//https://leetcode.com/problems/happy-number/

//TC:O(log n+log log n+2*243*3)   //SC:O(1)     
int nextNum(int n)      
    {
        int sum=0;
        while(n)
        {
            sum+=(n%10)*(n%10);
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slower=n;
        int faster=nextNum(n);
        while(faster!=1)
        {
            if(slower==faster)
                return false;
            slower=nextNum(slower);
            faster=nextNum(nextNum(faster));
        }
        return true;
    }