//https://leetcode.com/problems/single-number/

//Sorting   //TC:O(n log n) //SC:O(1)

//Set       //TC:O(n log n) //SC:O(n)


//TC:O(2n)   //SC:O(n)
int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto it:mp)
        {
            if(it.second==1)
                return it.first;
        }
        return 0;
    }

//TC:O(n)   //SC:O(1)
int singleNumber(vector<int>& nums) {   
        int ans=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            ans=ans^nums[i];    //use XOR operator
        }
        return ans;
    }