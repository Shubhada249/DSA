//https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/
//TC:O(n log n+n log high)  //SC:O(1)
int fun(int val,vector<int> &nums,int n)
    {
        int cnt=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]-nums[i-1]<=val)
            {
                cnt++;
                i++;
            }
        }
        return cnt;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int low=0,high=0,n=nums.size();
        for(int i=1;i<n;i++)
        {
            high=max(high,nums[i]-nums[i-1]);
        }
        int ans=high;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int pairs=fun(mid,nums,n);
            if(pairs>=p)
            {
                ans=min(ans,mid);
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }