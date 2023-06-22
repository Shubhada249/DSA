//https://leetcode.com/problems/next-greater-element-i/
//TC:O(n1+n2)   //SC:O(n1)
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        vector<int> ans(n1,-1);
        unordered_map<int,int> mp;
        for(int i=0;i<n1;i++)
        {
            mp[nums1[i]]=i;
        }
        
        stack<int> st;
        for(int i=n2-1;i>=0;i--)
        {
            int a=-1;
            while(!st.empty() && st.top()<=nums2[i])
                st.pop();
            if(!st.empty())
                a=st.top();
            st.push(nums2[i]);
            if(mp.find(nums2[i])!=mp.end())
            {
                ans[mp[nums2[i]]]=a;
            }
                
        }
        return ans;
        
    }