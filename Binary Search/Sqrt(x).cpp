//https://leetcode.com/problems/sqrtx/

//TC:O(log n)   //SC:O(1)
int mySqrt(int x) {
        int low=0,high=(x/2)+1,ans;
        while(low<=high)
        {
            long long mid=low+(high-low)/2;
            if(mid*mid==x)
                return mid;
            else if(mid*mid>x)
                high=mid-1;
            else
            {
                ans=mid;
                low=mid+1;
            }
        }
        return ans;
    }