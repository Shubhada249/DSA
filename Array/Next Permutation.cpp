//https://leetcode.com/problems/next-permutation/

//TC:O(n)   //SC:O(1)
void nextPermutation(vector<int>& nums) {
        int n=nums.size(),i;
        for(i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
                break;
        }
        if(i>=0)
        {
            int ind;
            for(int j=n-1;j>i;j--)
            {
                if(nums[j]>nums[i])
                {
                    ind=j;
                    break;
                }
            }
            swap(nums[i],nums[ind]);
        }
        reverse(nums.begin()+i+1,nums.end());
    }
    