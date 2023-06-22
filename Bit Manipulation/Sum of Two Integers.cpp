//https://leetcode.com/problems/sum-of-two-integers/

//TC:O(log b)   //SC:O(1)
int getSum(int a, int b) {
        if(b==0)
            return a;
        return getSum(a^b,(unsigned int)(a&b)<<1);
    }

//TC:O(log b)   //SC:O(1)
    int getSum(int a, int b) {
    int XOR,carry;
        while(b!=0)
        {
            XOR=a^b;
            carry=(unsigned int)(a&b)<<1;
            a=XOR;
            b=carry;
        }
        return a;
    }