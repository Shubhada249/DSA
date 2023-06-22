//https://leetcode.com/problems/missing-number/

//TC:O(n)//SC:O(1)
int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int nums_sum=accumulate(nums.begin(),nums.end(),0);
        int sum0_n=n*(n+1)/2;
        return sum0_n-nums_sum;
    }