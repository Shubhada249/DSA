//https://leetcode.com/problems/subarray-sum-equals-k/

//TC:O(n^2)     //SC:O(1)
int subarraySum(vector<int>& nums, int k) {
        int count=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum+=nums[j];
                if(sum==k)
                    count++;
            }
        }
        return count;
    }

//TC:O(n)   //SC:O(n)
int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(),ans=0;
        unordered_map<int,int> mp;        
        int ps=nums[0];
        if(ps==k)
            ans++;
        mp[nums[0]]++;
        for(int i=1;i<n;i++)
        {
            ps+=nums[i];
            if(ps==k)
                ans++;
            int req=ps-k;
            if(mp.find(req)!=mp.end())
            {
                ans+=mp[req];
            }
            mp[ps]++;
        }    
        return ans;
    }