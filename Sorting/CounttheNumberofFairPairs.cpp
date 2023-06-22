//https://leetcode.com/problems/count-the-number-of-fair-pairs/

/*Note:0 <= i < j < n
above condition tells that if you are considering (i,j) pair in answer then do not consider (j,i) pair in answer.*/

//TC:O(n^2)     //SC:O(1)
long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int sum=nums[i]+nums[j];
                if(sum>=lower && sum<=upper)
                    ans++;
            }
        }
        return ans;
    }

//TC:O(n log n+2n)     //SC:O(1)
long long NoOfPairs(int limit,vector<int>& nums)    //TC:O(n)
    {   
        int n=nums.size(),i=0,j=n-1;
        long long ans=0;
        while(i<j)
        {
            while(i<j && nums[i]+nums[j]>limit)
                j--;
            ans+=j-i;
            i++;
        }
        return ans;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        return NoOfPairs(upper,nums)-NoOfPairs(lower-1,nums);
    }