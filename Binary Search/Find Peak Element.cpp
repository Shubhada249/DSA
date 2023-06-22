//https://leetcode.com/problems/find-peak-element/

//TC:O(log n)   //SC:O(1)
int fun(int mid,vector<int>& nums,int n)
    {
        if(mid==0)
        {
            if(nums[mid+1]<nums[mid])
                return 0;
            else
                return 1;
        }
        if(mid==n-1)
        {
            if(nums[mid-1]<nums[mid])
                return 0;
            else
                return -1;
        }
        if(nums[mid-1]<nums[mid] && nums[mid+1]<nums[mid])
            return 0;
        else if(nums[mid-1]>nums[mid])
            return -1;
        else
            return 1;
    }
    int findPeakElement(vector<int>& nums) {
        int n=nums.size(),low=0,high=n-1;
        if(n==1)
            return 0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int a=fun(mid,nums,n);
            if(a==0)
                return mid;
            else if(a==-1)
                high=mid-1;
            else
                low=mid+1;
        }
        return n-1;
    }