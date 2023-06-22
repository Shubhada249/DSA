//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

//TC:O(n)   //SC:O(1)
int fun(vector<int>& nums,int low,int high)
    {
        int n=nums.size();
        while(low<=high)
        {
            
            int mid=low+(high-low)/2;
            if(nums[low]<nums[high]) 
                return nums[low];
            else if(mid==0 && nums[n-1]>nums[mid])
                return nums[mid];
            else if(mid!=0 && nums[mid-1]>nums[mid])
                return nums[mid];
            else if(nums[low]>nums[mid])
                high=mid-1;
            else if(nums[mid]>nums[high])
                low=mid+1;
            else
                return min(fun(nums,low,mid-1),fun(nums,mid+1,high));                     
        }
        return nums[0];
    }
    int findMin(vector<int>& nums) {
        int n=nums.size(),low=0,high=n-1;
        if(n==1)
            return nums[0];
        return fun(nums,low,high);
                
    }