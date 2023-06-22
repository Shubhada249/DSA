//https://leetcode.com/problems/count-number-of-nice-subarrays/

//TC:O(n)   //SC:O(n)
int numberOfSubarrays(vector<int>& nums, int k) {
        int i=0,j=0,n=nums.size(),odd=0,ans=0,count=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2!=0)
                count++;
            mp[count]++;
        }
        mp[0]++;
        
        for(auto it:mp)
        {
            if(mp.find(k+it.first)!=mp.end())
            {                
                ans+=it.second*mp[(k+it.first)];
            }
        }
        return ans;
    }

//TC:O(n)   //SC:O(1)
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i=0,j=0,n=nums.size(),odd=0,ans=0;
        
        while(j<n)
        {
            if(nums[j]%2!=0)
                odd++;
            if(odd<k)
                j++;
            else if(odd==k)
            {
                int previ=i;
                while(i<n && nums[i]%2==0)
                    i++;
                int res=i-previ+1;
                ans+=res;
                i++;
                odd--;
                j++;
                while(j<n && nums[j]%2==0)
                {
                    ans+=res;
                    j++;
                }
            }
        }
        return ans;
    }