//https://practice.geeksforgeeks.org/problems/count-digits5716/1
//Y
//Edge Case: if any digit is 0
//TC:O(log 10 (N)) //SC:O(1)
int evenlyDivides(int N)    
{
    //code here
    int num=N,count=0;
    while(num!=0)
    {
        int d=num%10;
        if(d!=0 && N%d==0)
            count++;
        num=num/10;
    }
    return count;
}