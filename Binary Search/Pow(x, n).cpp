//https://leetcode.com/problems/powx-n/

//TC:O(log n)   //SC:O(1)
double fun(double x,long long p)
    {
        if(p==0)
            return 1;
        if(p%2==0)
            return fun(x*x,p/2);
        else 
            return x*fun(x,p-1);
    }
    double myPow(double x, int n) {
        long long p=(long long)n;
        if(n<0)
        {
            x=1/x;
            p=-p;
        }
        return fun(x,p);
    }