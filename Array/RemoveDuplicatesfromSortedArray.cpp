//https://leetcode.com/problems/remove-duplicates-from-sorted-array/

//TC:O(2n)  //SC:O(1)
int removeDuplicates(vector<int>& nums) {
        int i=0,j=1,n=nums.size();
        while(j<n)
        {
            while(j<n && nums[i]==nums[j])
                j++;
            if(j==n)
                break;
            nums[i+1]=nums[j];
            i++;
            j++;
        }
        return i+1;
    }