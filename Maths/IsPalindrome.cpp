 //https://leetcode.com/problems/palindrome-number/

 //TC:O(log 10 X)//sc:O(1)
 //Edge case: integer Overflow
 bool isPalindrome(int x) 
 {
    if(x<0)
        return false;
    int num=x,ans=0,maxi=INT_MAX/10;
    while(num)
    {
        if(ans>maxi)
            return false;
        else if(ans==maxi && num>INT_MAX%10)
            return false;
        else
        {
            ans=ans*10+(num%10);
            num/=10;
        }
    }
    if(ans==x)
        return true;
    return false;
}

//TC:O(log 10 X)//sc:O(1)
//Edge case: 1.odd no. of digits in number    2.x=no. ending with zero     3.x=0
bool isPalindrome(int x) 
{
    if(x<0 || x%10==0 && x!=0)
        return false;
    int num=x,ans=0;
    while(ans<num)
    {
            ans=ans*10+(num%10);
            num/=10;
    }
    if(ans==num || ans/10==num)
        return true;
    return false;
}