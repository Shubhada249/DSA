//https://leetcode.com/problems/remove-element/
//TC:O(n)   //SC:O(1)
int removeElement(vector<int>& nums, int val) {
        int i=0,j=0,n=nums.size();
        while(j<n)
        {
            if(nums[j]==val)
                j++;
            else
            {
                nums[i]=nums[j];
                i++;
                j++;
            }
        }
        return i;
    }