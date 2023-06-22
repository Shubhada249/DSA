//https://practice.geeksforgeeks.org/problems/armstrong-numbers2727/1
//TC:O(log 10 n)//SC:O(1)
string armstrongNumber(int n){
        // code here
        int num=n,ans=0;
        while(num)
        {
            ans+=(num%10)*(num%10)*(num%10);
            num/=10;
        }
        if(ans==n)
            return "Yes";
        return "No";
    }