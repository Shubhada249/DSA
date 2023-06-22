//https://leetcode.com/problems/reverse-integer/    
//N 
//Edge Case: 1.Overflow     2.num=INT_MIN
//TC:O(log 10 (N)) //SC:O(1)
int reverse(int num) 
{
    bool neg=false;
    if(num==INT_MIN)    
        return 0;
    if(num<0)   
    {
        neg=true;
        num=0-num;
    }
    int ans=0;
    int maxi=INT_MAX/10;
    while(num)
    {
        if(ans>maxi)       
            return 0; 
        else if(ans==maxi && num>INT_MAX%10)
            return 0;
        else
        {
            ans=ans*10+(num%10);
            num/=10;
        }
    }
    if(neg)
        return 0-ans;
    return ans;
}