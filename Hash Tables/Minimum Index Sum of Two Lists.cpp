//https://leetcode.com/problems/minimum-index-sum-of-two-lists/

//TC:O(m+n) //SC:O(2m)
vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> l1;
        for(int i=0;i<list1.size();i++)
        {
            l1[list1[i]]=i;
        }
        
        unordered_map<string,int> mp;
        int mini=INT_MAX;
        for(int i=0;i<list2.size();i++)
        {
            if(l1.find(list2[i])!=mp.end())
            {
                mp[list2[i]]=l1[list2[i]]+i;
                mini=min(mini,mp[list2[i]]);
            }
        }
        vector<string> ans;
        for(auto it:mp)
        {
            if(it.second==mini)
                ans.push_back(it.first);
        }
        return ans;
    }