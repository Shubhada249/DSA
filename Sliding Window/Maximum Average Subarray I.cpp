//https://leetcode.com/problems/maximum-average-subarray-i/

//TC:O(n^2)     //SC:O(1)
double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        double ans=INT_MIN;
        for(int i=0;i<=n-k;i++)
        {
            long long sum=0;
            for(int j=i;j<i+k;j++)
            {
                sum+=nums[j];
            }
            ans=max(ans,sum/double(k));
        }
        return ans;
    }

//TC:O(n)   //SC:O(1)
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size(),i=0,j=0,sum=0;
        double maxi=INT_MIN;
        while(j<n)
        {
            sum=sum+nums[j];
            if(j-i+1<k)
                j++;
            else if(j-i+1==k)
            {
                maxi=max(maxi,(double)sum/k);
                sum=sum-nums[i];
                i++;
                j++;
            }
        }
        return maxi;
    }