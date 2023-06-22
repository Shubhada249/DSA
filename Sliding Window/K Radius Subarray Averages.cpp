//https://leetcode.com/problems/k-radius-subarray-averages/

//TC:O(n)   //SC:O(1)
vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size(),ws=2*k+1;
        vector<int> ans(n,-1);
        int i=0,j=0;
        long long sum=0;
        while(j<n)
        {
            sum+=nums[j];
            if(j-i+1<ws)
                j++;
            else if(j-i+1==ws)
            {
                int ind=(i+j)/2;
                ans[ind]=sum/ws;
                sum-=nums[i];
                i++;
                j++;
            }
        }
        return ans;
    }