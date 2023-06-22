//https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

//NOTE:using map,multiset instead of dequeue will give TC O(n log n)
//TC:O(n)   //SC:O(n)
int longestSubarray(vector<int>& nums, int limit) {
        deque <int> maxi,mini;
        int i=0,j=1,ans=1,n=nums.size();
        maxi.push_back(nums[0]);
        mini.push_back(nums[0]);
        while(j<n)
        {
            if(nums[j]>maxi.back())
            {
                while(!maxi.empty() && maxi.back()<nums[j])
                    maxi.pop_back();
                maxi.push_back(nums[j]);
            }
            else
                maxi.push_back(nums[j]);
            
            
            if(nums[j]<mini.back())
            {
                while(!mini.empty() && nums[j]<mini.back())
                    mini.pop_back();
                mini.push_back(nums[j]);
            }
            else
                mini.push_back(nums[j]);
            
            if(maxi.front()-mini.front()<=limit)
            {
                ans=max(ans,j-i+1);
                j++;
            }
            else
            {
                while(maxi.front()-mini.front()>limit)
                {
                    if(nums[i]==maxi.front())
                        maxi.pop_front();
                    if(nums[i]==mini.front())
                        mini.pop_front();
                    i++;                
                }
                j++;
            }
        }
        return ans;
    }