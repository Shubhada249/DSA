//https://leetcode.com/problems/maximum-erasure-value/

//TC:O(n)   //SC:O(10^4)
int maximumUniqueSubarray(vector<int>& nums) {
        int i=0,j=0,sum=0,n=nums.size(),count=0,ans=0;
        unordered_map<int,int> mp;
        
        while(j<n)
        {
            sum+=nums[j];
            mp[nums[j]]++;
            if(mp[nums[j]]==1)
                count++;
            
            if(count==j-i+1)
            {
                ans=max(ans,sum);
                j++;
            }
            else 
            {
                while(count<j-i+1)
                {
                    sum-=nums[i];
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0)
                        count--;
                    i++;
                }
                j++;
            }
        }
        return ans;
    }