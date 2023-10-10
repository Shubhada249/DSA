//https://leetcode.com/problems/maximum-product-subarray/
//TC:O(n)   //SC:O(1)
int maxProduct(vector<int>& nums) {
        int n=nums.size(),ans=nums[0],temp=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                ans=max(ans,nums[i]);
                temp=1;
            }
            else
            {
                temp=temp*nums[i];
                ans=max(max(ans,nums[i]),temp);
            }
        }
        temp=1;
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]==0)
            {
                ans=max(ans,nums[i]);
                temp=1;
            }
            else
            {
                temp=temp*nums[i];
                ans=max(max(ans,nums[i]),temp);
            }
        }
        return ans;
    }