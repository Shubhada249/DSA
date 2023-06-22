//https://leetcode.com/problems/maximum-sum-circular-subarray/

//TC:O(n^2)     //SC:O(1)
int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        
        int total=accumulate(nums.begin(),nums.end(),0);
        int ans=total;
        for(int i=0;i<n;i++)
        {
            int sum=0;
            int cnt=0;
            for(int j=i;cnt<(n/2);j=(j+1)%n)
            {
                sum+=nums[j];
                ans=max(ans,max(sum,total-sum));
                cnt++;
            }            
        }
        return ans;
    }

//TC:O(n)     //SC:O(1)
int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int temp_min=0,mini=INT_MAX,maxi=INT_MIN,temp_max=0,total=0;
        for(int i=0;i<n;i++)
        {
            total+=nums[i];
            temp_min+=nums[i];
            mini=min(mini,temp_min);
            if(temp_min>0)
                temp_min=0;
            temp_max+=nums[i];
            maxi=max(maxi,temp_max);
            if(temp_max<0)
                temp_max=0;
        }
        if(total==mini)
            return maxi;
        return max(total-mini,maxi);
    }