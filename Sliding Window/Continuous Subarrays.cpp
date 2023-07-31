//https://leetcode.com/problems/continuous-subarrays/

//TC:O(n log n)     //SC:O(n)
long long continuousSubarrays(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        int i=0,j=0,maxi,mini;
        map<int,int> mp;
        while(j<n)
        {
            mp[nums[j]]++;
            auto it=mp.begin();
            mini=it->first;
            auto it1=mp.end();
            it1--;
            maxi=it1->first;
            if(maxi-mini>=0 && maxi-mini<=2)
            {
                ans+=(j-i+1);
                j++;
            }
            else
            {
                while(i<n && (!(maxi-mini>=0 && maxi-mini<=2)))
                {
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0)
                        mp.erase(nums[i]);
                    i++;                    
                    auto it2=mp.begin();
                    mini=it2->first;
                    auto it3=mp.end();
                    it3--;
                    maxi=it3->first;
                }
                // int k=j-i;
                // ans+=(k*(k+1)/2)+1;
                ans+=j-i+1;
                j++;
            }
        }
        return ans;
    }