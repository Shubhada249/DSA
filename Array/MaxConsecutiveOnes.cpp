//https://leetcode.com/problems/max-consecutive-ones/

//TC:O(n)   //SC:O(1)
int findMaxConsecutiveOnes(vector<int>& nums) {
        nums.push_back(0);
        int count_ones=0;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
                count_ones++;
            else
            {
                ans=max(ans,count_ones);
                count_ones=0;
            }
        }
        nums.pop_back();
        return ans;
    }