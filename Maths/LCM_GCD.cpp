//https://practice.geeksforgeeks.org/problems/lcm-and-gcd4516/1

//gcd(a,b)=gcd(b, a % b)
//TC:O(log(min(a,b)))//SC:O(1)

vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
        long long a=max(A,B),b=min(A,B),R;
        while(b)
        {
            R=a%b;
            a=b;
            b=R;
        }
        long long gcd=a;
        long long lcm=A*B/gcd;
        return {lcm,gcd};
    }