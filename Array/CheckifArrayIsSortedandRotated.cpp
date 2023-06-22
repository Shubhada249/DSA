//https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
//TC:O(N)//SC:O(1)
bool check(vector<int>& nums) {
        int i=1,l=0,n=nums.size(),prev=nums[0];
        if(n==1)
            return true;
        do
        {
            if(nums[i]<prev)
                l++;
            prev=nums[i];
            i=(i+1)%n;
        }while(i!=1);
        if(l<=1)
            return true;
        return false;
    }