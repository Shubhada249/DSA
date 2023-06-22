//https://leetcode.com/problems/two-sum/

//Brute Force:O(n^2)

//TC:O(n log n+2n)  //SC:O(n)
vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> v;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end(),[&](pair<int,int> p1,pair<int,int> p2){return p1.first<p2.first;});
        int i=0,j=n-1;
        
        while(1)
        {
            if(v[i].first+v[j].first==target)
                return {v[i].second,v[j].second};
            else if(v[i].first+v[j].first>target)
                j--;
            else
                i++;
        }
        return {0,1};
    }

//TC:O(n)  //SC:O(n)
vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> um;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            auto it=um.find(target-nums[i]);    //TC:O(1)
            if(it!=um.end())
                return {i,(*it).second};
            else
                um[nums[i]]=i;
        }
        return {0,1};
    }