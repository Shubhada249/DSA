//https://leetcode.com/problems/rotate-array/

//TC:O(2n)//SC:O(n)
void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++)
        {
            int ind=(i+k)%n;
            ans[ind]=nums[i];
        }
        nums=ans;
    }

//TC:O(2n)//SC:O(1)
void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }

