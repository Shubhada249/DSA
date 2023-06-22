//https://practice.geeksforgeeks.org/problems/prime-number2314/1

//TC:O(sqrt(N))//SC:O(1)
//Edge Case: N=1 or N=0 ...acc to constraints
int isPrime(int N){
        // code here
        if(N==1)
            return 0;
        for(int i=2;i<=sqrt(N);i++)
        {
            if(N%i==0)
                return 0;
        }
        return 1;
    }