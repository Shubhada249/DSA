//https://leetcode.com/problems/contains-duplicate/

//TC:O(N log N+N)   //SC:O(1)
bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1])
                return true;
        }
        return false;
    }


//TC:O(N)   //SC:O(N)
bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]>1)
                return true;
        }
        return false;
    }