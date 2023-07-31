//https://leetcode.com/problems/container-with-most-water/

//TC:O(n^2)     //SC:O(1)
int maxArea(vector<int>& height) {
        int n=height.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=n-1;j>i;j--)
            {
                if(height[j]>=height[i])
                {                   
                    ans=max(ans,height[i]*(j-i));
                    break;
                }
            }
            for(int j=0;j<i;j++)
            {
                if(height[j]>=height[i])
                {
                    ans=max(ans,height[i]*(i-j));
                    break;
                }
            }
        }
        return ans;
    }

//TC:O(n)   //O(1)
int maxArea(vector<int>& height) {
        int n=height.size();
        int ans=0;
        int i=0,j=n-1;
        while(i<j)
        {
            ans=max(ans,min(height[i],height[j])*(j-i));
            if(height[i]==height[j])
            {
                i++;
                j--;
            }
            else if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return ans;
    }