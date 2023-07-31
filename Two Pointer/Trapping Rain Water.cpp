//https://leetcode.com/problems/trapping-rain-water/

//TC:O(n)   //SC:O(n)
int trap(vector<int>& height) {
        int n=height.size();
        vector<int> ll(n,height[0]),rl(n,height[n-1]);
        for(int i=1;i<n;i++)
        {
            ll[i]=max(ll[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--)
        {
            rl[i]=max(rl[i+1],height[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=(min(ll[i],rl[i])-height[i]);
        }
        return ans;
    }

//TC:O(n)   //SC:O(1)
int trap(vector<int>& height) {
        int n=height.size(),l=0,r=n-1,lm=0,rm=0,ans=0;
        while(l<r)
        {
            if(height[l]<=height[r])
            {
                if(height[l]>=lm)
                    lm=height[l];
                else
                    ans+=lm-height[l];
                l++;
            }
            else
            {
                if(height[r]>=rm)
                    rm=height[r];
                else
                    ans+=rm-height[r];
                r--;
            }
        }
        return ans;
    }