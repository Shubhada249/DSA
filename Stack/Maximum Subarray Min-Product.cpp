//https://leetcode.com/problems/maximum-subarray-min-product/

//TC:O(n^2)     //SC:O(1)
int maxSumMinProduct(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int mini=nums[i];
            long long sum=0;
            for(int j=i;j<n;j++)
            {
                mini=min(mini,nums[j]);
                sum+=nums[j];
                ans=max(ans,sum*mini);
            }
        }
        return ans % 1000000007;
    }

//TC:O(n)   //SC:O(n)
int maxSumMinProduct(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        vector<int> sl(n,-1),sr(n,n);
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && nums[st.top()]>=nums[i])
                st.pop();
            if(!st.empty())
                sl[i]=st.top();
            st.push(i);    
        }
        st=stack<int>();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && nums[st.top()]>=nums[i])
                st.pop();
            if(!st.empty())
                sr[i]=st.top();
            st.push(i); 
        }
        vector<long long> ps(n,nums[0]);
        for(int i=1;i<n;i++)
        {
            ps[i]=ps[i-1]+nums[i];
        }
        for(int i=0;i<n;i++)
        {
            if(sl[i]!=-1)
                ans=max(ans,(ps[sr[i]-1]-ps[sl[i]])*nums[i]);
            else
                ans=max(ans,(ps[sr[i]-1])*nums[i]);
        }
        return ans % 1000000007;
    }