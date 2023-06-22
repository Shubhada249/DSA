//https://leetcode.com/problems/find-the-winner-of-the-circular-game/
//TC:O(n^2)     //SC:O(n)       //Brute force
int findTheWinner(int n, int k) {
        vector<int> vec;
        for(int i=1;i<=n;i++)
        {
            vec.push_back(i);
        }
        int i=0,count=1;
        while(vec.size()!=1)
        {
            while(count!=k)
            {
                count++;
                i=(i+1)%vec.size();
            }
            vec.erase(vec.begin()+i);
            count=1;
            
        }
        return vec[0];
    }

//TC:O(n)     //SC:O(n)     //Recursion
int fun(vector<int> &vec,int i,int k)
    {
        if(vec.size()==1)
            return vec[0];
                
        int d=(i+k-1)%vec.size();
        vec.erase(vec.begin()+d);
        return fun(vec,d,k);
            
    }
    int findTheWinner(int n, int k) {
        vector<int> vec;
        for(int i=1;i<=n;i++)
        {
            vec.push_back(i);
        }

        return fun(vec,0,k);
    }

//TC:O(n)     //SC:O(n) 
int findTheWinner(int n, int k) {
        if(n==1)
            return 1;
        int ans=(findTheWinner(n-1,k)+k)%n;
        return ans==0?n:ans;       
    }

//TC:O(n)     //SC:O(1)     //Iterative version of above solution
int findTheWinner(int n, int k) {
        int ans=1;
        for(int i=2;i<=n;i++)
        {
            ans=(ans+k)%i;
            ans=(ans==0)?i:ans;
        }
        return ans;
    }