//https://practice.geeksforgeeks.org/problems/find-all-factorial-numbers-less-than-or-equal-to-n3548/0?problemType=functional&difficulty[]=-1&page=1&query=problemTypefunctionaldifficulty[]-1page1&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-all-factorial-numbers-less-than-or-equal-to-n


//TC:O(K) K:no. of factorialNumbers //SC:O(K)
void fun(int i,long long ans,long long N,vector<long long> &vec)
    {
        if(ans>N)
            return;
        vec.push_back(ans);
        ans*=i;
        fun(i+1,ans,N,vec);
    }
    vector<long long> factorialNumbers(long long N)
    {
        // Write Your Code here
        vector<long long> vec;
        long long ans=1;
        int i=2;
        fun(i,ans,N,vec);
        return vec;
    }



//TC:O(K) K:no. of factorialNumbers //SC:O(1)
vector<long long> factorialNumbers(long long N)
    {
        // Write Your Code here
        vector<long long> vec;
        long long ans=1;
        for(int i=2;ans<=N;i++)
        {
            vec.push_back(ans);
            ans*=i;
        }
        return vec;
    }