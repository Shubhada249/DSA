//https://leetcode.com/problems/contains-duplicate-ii/

//TC:O(n)   //SC:O(n)
bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size(),i=0,j=0;
        k++;
        unordered_map<int,int> mp;
        while(j<n)
        {
            mp[nums[j]]++;
            if(mp[nums[j]]==2)
                return true;
            
            if(j-i+1<k)
                j++;
            else if(j-i+1==k)
            {
                mp[nums[i]]--;
                i++;
                j++;
            }
        }
        return false;
    }