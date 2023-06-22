//https://leetcode.com/problems/count-the-number-of-good-subarrays/

//TC:O(N)//SC:O(N)

#define ll long long
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        ll nop=0,ans=0;
        map<ll,ll> mp;
        int i=0,j=0,n=nums.size();
        while(j<n)
        {
            //nop+=count(nums.begin()+i,nums.begin()+j,nums[j]);
            nop+=mp[nums[j]];
            mp[nums[j]]++;
            if(nop<k)
                j++;
            else
            {
                while(nop>=k)
                {
                    ans++;
                    ans+=n-j-1;
                    //nop-=count(nums.begin()+i+1,nums.begin()+j+1,nums[i]);
                    mp[nums[i]]--;
                    nop-=mp[nums[i]];
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};