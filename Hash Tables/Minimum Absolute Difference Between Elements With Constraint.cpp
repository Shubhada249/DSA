//https://leetcode.com/problems/minimum-absolute-difference-between-elements-with-constraint/
//TC:O(n log n)     //SC:O(n)
int minAbsoluteDifference(vector<int>& nums, int x) {
        int n=nums.size();
        set<int> s;
        int ans=INT_MAX;
        for(int i=x;i<n;i++)
        {
            s.insert(nums[i-x]);
            auto it=s.lower_bound(nums[i]);
            if(it!=s.end())
            {
                cout<<*it-nums[i]<<" ";
                ans=min(ans,(*it-nums[i]));
            }
            if(it!=s.begin())
            {
                it--;   
                cout<<nums[i]-*it<<" ";
                ans=min(ans,(nums[i]-(*it)));
            }
        }
        return ans;
    }