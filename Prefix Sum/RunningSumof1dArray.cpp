//https://leetcode.com/problems/running-sum-of-1d-array/

//TC:O(n)   //SC:O(1)   //not in place solution
vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        ans[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            ans[i]=ans[i-1]+nums[i];
        }
        return ans;
    }

//TC:O(n)   //SC:O(1)   //in place solution
vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        
        for(int i=1;i<n;i++)
        {
            nums[i]=nums[i-1]+nums[i];
        }
        return nums;
    }