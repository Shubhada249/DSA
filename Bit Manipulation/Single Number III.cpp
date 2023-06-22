//https://leetcode.com/problems/single-number-iii/

//TC:O(n)   //SC:O(n)
vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        vector<int> ans;
        for(auto it:mp)
        {
            if(it.second==1)
                ans.push_back(it.first);
        }
        return ans;
    }

//TC:O(n)   //SC:O(1)
vector<int> singleNumber(vector<int>& nums) {
        int axor=0;
        for(int i=0;i<nums.size();i++)
        {
            axor=axor^nums[i];
        }
        bool ch=true;
        int cnt=0;
        while(ch)
        {
            if((axor&1)==1)
            {
                ch=false;
            }
            axor=axor>>1;
            cnt++;
        }
        cnt--;
        int mask=1<<cnt;
        int xor1=0,xor2=0;
        for(int i=0;i<nums.size();i++)
        {
            if((mask&nums[i])==0)
                xor1=xor1^nums[i];
            else
                xor2=xor2^nums[i];
        }
        return {xor1,xor2};