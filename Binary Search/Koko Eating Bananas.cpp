//https://leetcode.com/problems/koko-eating-bananas/

//TC:O(n log(max_element from piles))   //SC:O(1)

long long atleastReqHours(int mid,vector<int>& piles,int n)
    {
        long long atleast=0;
        for(int i=0;i<n;i++)
        {
            if(piles[i]%mid!=0)
                atleast++;
            atleast+=piles[i]/mid;
        }
        return atleast;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1,high=*max_element(piles.begin(),piles.end());
        int ans;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            long long atleast=atleastReqHours(mid,piles,n);
            
            if(atleast<=h)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }