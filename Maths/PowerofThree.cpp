//https://leetcode.com/problems/power-of-three/

//TC:O(x) (3^x=n)   //SC:O(1)
bool isPowerOfThree(int n) {
        if(n<0)
            return false;
        long long num=1;
        while(n>num)
        {
            num*=3;
        }
        return n==num;
    }

//TC:O(x) (3^x=n)   //SC:O(x)
bool fun(long long num,int n)
    {
        if(num==n)
            return true;
        else if(n<num)
            return false;
        return fun(num*3,n);
    }
    bool isPowerOfThree(int n) {
        if(n<0)
            return false;
        long long num=1;
        return fun(num,n);
    }

//TC:O(1)   //SC:O(1)
bool isPowerOfThree(int n) {
        if(n<=0)
            return false;
        
        double a=log10(n)/log10(3);
        // double a1=log(n)/log(3);
        // std::cout.precision(20);
        // cout<<a<<" "<<a1;
        int b=a;
        double c=a-b;
        if(c==0)
            return true;
        return false;
    }