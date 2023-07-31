//https://leetcode.com/problems/longest-consecutive-sequence/

//TC:O(n log n)     //SC:O(1)
//Edge case:when duplicates exist in array
int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0,dup=0;
        int i=0,j=0;
        while(j<n)
        {
            if(j!=0 && nums[j]==nums[j-1]+1)
                j++;
            else if(j!=0 && nums[j]==nums[j-1])
            {
                dup++;
                j++;
            }
            else
            {
                ans=max(ans,j-i-dup);
                dup=0;
                i=j;
                j++;
            }
        }
        ans=max(ans,j-i-dup);
        return ans;
    }

//TC:O(n)     //SC:O(n)
int longestConsecutive(vector<int>& nums) {
        int n=nums.size(),ans=0;
        unordered_set<int> st;
        for(auto num:nums)
            st.insert(num);
        for(auto num:st)
        {
            auto it=st.find(num-1);
            if(it==st.end())
            {
                int c=1;
                while(st.find(num+1)!=st.end())
                {
                    c++;
                    num++;
                }
                ans=max(ans,c);
            }
        }
        return ans;
    }
