//https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/

//TC:O(n log n+n)   //SC:O(1)
int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0,j=0,ans=INT_MAX;
        while(j<n)
        {
            if(j-i+1<k)
                j++;
            else if(j-i+1==k)
            {
                ans=min(ans,nums[j]-nums[i]);
                i++;
                j++;
            }
        }
        return ans;
    }