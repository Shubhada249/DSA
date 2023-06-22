//https://leetcode.com/problems/first-bad-version/

//TC:O(log n)   //SC:O(1)
int firstBadVersion(int n) {
        int low=1,high=n,ans;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(isBadVersion(mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }