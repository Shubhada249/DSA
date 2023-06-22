//https://leetcode.com/problems/find-the-duplicate-number/

//TC:O(n)   //SC:O(1)
int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int s=nums[0],f=nums[nums[0]];
        while(s!=f)
        {
            s=nums[s];
            f=nums[nums[f]];
        }
        s=nums[s];
        f=nums[0];
        while(s!=f)
        {
            s=nums[s];
            f=nums[f];
        }
        return s;
    }