//https://leetcode.com/problems/jump-game/

//TC:O(n)   //SC:O(1)
bool canJump(vector<int>& nums) {
        int n=nums.size();
        int last=n-1;
        for(int ind=n-2;ind>=0;ind--)
        {
            int maxPossible=ind+nums[ind];
            if(last<=maxPossible)
                last=ind;
        }
        if(last==0)
            return true;
        else
            return false;
    }