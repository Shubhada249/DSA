//https://leetcode.com/problems/intersection-of-two-arrays/

//TC:O(n1+n2)  //SC:O(n2)
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        int n1=nums1.size(),n2=nums2.size();
        for(int i=0;i<n2;i++)
        {
            mp[nums2[i]]++;
        }

        vector<int> ans;
        for(int i=0;i<n1;i++)
        {
            if(mp[nums1[i]]!=0)
            {
                ans.push_back(nums1[i]);
                mp[nums1[i]]=0;
            }
        }
        return ans;
    }