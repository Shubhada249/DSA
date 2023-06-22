//https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

//TC:O(n)       //SC:O(1)
int longestSubarray(vector<int>& nums) {
        int n=nums.size(),i=0,j=0,nz=0,ans=0;
        while(j<n)
        {
            if(nums[j]==0)
                nz++;
            
            if(nz<2)
            {
                ans=max(ans,j-i);
                j++;
            }
            else if(nz==2)
            {
                while(nz==2)
                {
                    if(nums[i]==0)
                        nz--;
                    i++;
                }
                j++;
            }
        }
        return ans;
    }