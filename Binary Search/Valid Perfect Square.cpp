//https://leetcode.com/problems/valid-perfect-square/

//TC:O(log n)   //SC:O(1)

bool isPerfectSquare(int num) {
        int low=1,high=min(num/2+1,46340);
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(mid*mid==num)
                return true;
            else if(mid*mid<num)
                low=mid+1;
            else
                high=mid-1;
        }
        return false;
    }