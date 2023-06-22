//https://leetcode.com/problems/intersection-of-two-arrays-ii/

//TC:O(n1 log n1 +n2 log n2+min(n1,n2)) //SC:O(1)
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        vector<int> ans;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        for(int i=0,j=0;i<n1 && j<n2;)
        {
            if(nums1[i]==nums2[j])
            {
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i]<nums2[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        return ans;
    }

//TC:O(n1+n2+min(n1,n2))  //SC:O(n1+n2)
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,pair<int,int>> mp;
        int n1=nums1.size(),n2=nums2.size();
        for(int i=0;i<n1;i++)
        {
            mp[nums1[i]].first++;
        }
        for(int i=0;i<n2;i++)
        {
            mp[nums2[i]].second++;
        }
        vector<int> ans;
        for(auto it:mp)
        {
            pair<int,int> p=it.second;
            int count=min(p.first,p.second);
            while(count--)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }

//TC:O(n1+n2)  //SC:O(n1)
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        int n1=nums1.size(),n2=nums2.size();
        for(int i=0;i<n1;i++)
        {
            mp[nums1[i]]++;
        }
        vector<int> ans;
        for(int i=0;i<n2;i++)
        {
            if(mp.find(nums2[i])!=mp.end() && mp[nums2[i]]>0)
            {                
                ans.push_back(nums2[i]);
                mp[nums2[i]]--;                
            }
        }
        
        return ans;
    }