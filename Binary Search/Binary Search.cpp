//https://leetcode.com/problems/binary-search/

//TC:O(log n)   //SC:O(1)
int search(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1;
        while(start<=end)
        {
            int mid=start+((end-start)/2);
            if(target==nums[mid])
                return mid;
            else if(target<nums[mid])
            {
                end=mid-1;
            }
            else
                start=mid+1;
        }
        return -1;
    }