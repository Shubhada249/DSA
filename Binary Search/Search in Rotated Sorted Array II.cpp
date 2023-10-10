//https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
//TC:O(n)   //Sc:O(1)
int fun(vector<int>& nums,int low,int high,int n)
    {
        for(int i=low;i<=high;i++)
        {
            if(i!=0 && nums[i-1]>nums[i])
                return i;
        }
        return low;
    }
    int funMini(vector<int>& nums,int low,int high,int n)
    {    
        if(low==high)
            return low;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(nums[(n+mid-1)%n]>nums[mid])
                return mid;            
            else if(nums[low]>nums[mid])
                high=mid-1;
            else if(nums[mid]>nums[high])
                low=mid+1;
            else
            {
                int lh=funMini(nums,low,mid,n);
                int rh=funMini(nums,mid+1,high,n);
                if(lh!=-1 && nums[(n+lh-1)%n]>nums[lh])
                   return lh;  
                if(rh!=-1 && nums[(n+rh-1)%n]>nums[rh])
                    return rh;
                return fun(nums,low,high,n);
            }
        }
        return -1;
    }
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1;
        int mini=funMini(nums,0,n-1,n);
        cout<<mini;
        if(target>=nums[mini] && target<=nums[n-1])
        {
            low=mini;
            high=n-1;
        }
        else
        {
            low=0;
            high=mini-1;
        }
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
                return true;
            else if(nums[mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        return false;
    }