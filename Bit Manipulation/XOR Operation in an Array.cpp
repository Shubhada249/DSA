//https://leetcode.com/problems/xor-operation-in-an-array/

//TC:O(n)   //SC:O(1)
int xorOperation(int n, int start) {
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=ans^(start+2*i);
        }
        return ans;
    }

//TC:O(1)   //SC:O(1)
int xorOperation(int n, int start) {
        if(start%4<=1)
        {
            if((n-1)%4==0)
                return (start+2*(n-1));
            else if((n-1)%4==1)
                return (2);
            else if((n-1)%4==2)
                return (2)^(start+2*(n-1));
            else
                return 0;
        }
        else
        {
            if((n-1)%4==0)
                return (start);
            else if((n-1)%4==1)
                return (start)^(start+2*(n-1));
            else if((n-1)%4==2)
                return (2)^(start);
            else
                return (2)^(start)^(start+2*(n-1));
        }
    }