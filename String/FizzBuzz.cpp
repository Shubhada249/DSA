//https://leetcode.com/problems/fizz-buzz/
//TC:O(n)   //SC:O(1)
vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for(int i=1;i<=n;i++)
        {
            if(i%3 ==0 && i%5==0)       
                ans.push_back("FizzBuzz");
            else if(i%3==0)
                ans.push_back("Fizz");
            else if(i%5==0)
                ans.push_back("Buzz");
            else
                ans.push_back(to_string(i));
        }
        return ans;
    }


//The modulo operator is a very costly operation compared to other arithmetic operations hence it is a costly way to solve the problem in terms of time complexity. We can solve the same using simple addition operations.
//TC:O(n)   //SC:O(1)
vector<string> fizzBuzz(int n) {
        vector<string> ans(n,"");
        for(int i=15;i<=n;i+=15)
        {
            ans[i-1]="FizzBuzz";
        }
        for(int i=3;i<=n;i+=3)
        {
            if(ans[i-1]=="")
                ans[i-1]="Fizz";
        }
        for(int i=5;i<=n;i+=5)
        {
            if(ans[i-1]=="")
                ans[i-1]="Buzz";
        }
        for(int i=1;i<=n;i+=1)
        {
            if(ans[i-1]=="")
                ans[i-1]=to_string(i);
        }
        return ans;
    }