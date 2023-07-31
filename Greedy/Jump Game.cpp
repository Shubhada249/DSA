//https://leetcode.com/problems/jump-game/

//TC:O(n)   //SC:O(1)
bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxReach=0;
        for(int i=0;i<n;i++)
        {
            if(i>maxReach)
                return false;
            maxReach=max(maxReach,i+nums[i]);
        }
        return maxReach>=n-1;
    }