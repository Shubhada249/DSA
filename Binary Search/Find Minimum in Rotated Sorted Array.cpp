//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

//TC:O(log n)   //SC:O(1)
int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[low]<nums[high])
                return nums[low];
            else if(mid!=0 && nums[mid-1]>nums[mid])
                return nums[mid];
            else if(nums[low]>nums[mid])
                high=mid-1;
            else
                low=mid+1;
        }
        return nums[0];
    }