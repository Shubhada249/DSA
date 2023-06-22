//https://leetcode.com/problems/sum-of-all-subset-xor-totals/

 //TC:O(n*2^n)  //SC:O(1)
 int subsetXORSum(vector<int>& nums) {
        int ans=0,n=nums.size();
        for(int i=0;i<pow(2,n);i++)
        {
            int axor=0;
            for(int j=0;j<n;j++)
            {
                if((i &(1<<j))!=0)
                    axor=axor^nums[j];
            }
            ans+=axor;
            
        }
        return ans;
    }