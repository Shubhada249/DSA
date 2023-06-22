//https://leetcode.com/problems/search-in-rotated-sorted-array/

//TC:O(log n)   //SC:O(1)
int bs(int low,int high,vector<int>& nums,int target)
    {
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(target<nums[mid])
                high=mid-1;
            else
                low=mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size(),low=0,high=n-1,maxi;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(mid+1<n && nums[mid]>nums[mid+1])
            {
                maxi=mid;
                break;
            }
            else if(nums[low]>nums[mid])
                high=mid-1;
            else
                low=mid+1;
        }
        
        if(target<=nums[maxi] && target>=nums[0])
            return bs(0,maxi,nums,target);
        return bs(maxi+1,n-1,nums,target);
        
    }