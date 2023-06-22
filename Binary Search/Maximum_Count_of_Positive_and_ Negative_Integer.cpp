//https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/
//Y
//tc:O(log N)//sc:O(1)
class Solution {
public:
    int small_pos(vector<int>& nums)
    {
        int start=0,end=nums.size()-1,ans=-1;
        while(start<=end)
        {
            int mid=start+((end-start)/2);
            if(nums[mid]>0)
            {
                ans=mid;
                end=mid-1;
            }
            else
                start=mid+1;
        }
        return ans;
    }
    int large_neg(vector<int>& nums)
    {
        int start=0,end=nums.size()-1,ans=-1;
        while(start<=end)
        {
            int mid=start+((end-start)/2);
            if(nums[mid]<0)
            {
                ans=mid;
                start=mid+1;
            }
            else
                end=mid-1;
        }
        return ans;
    }
    int maximumCount(vector<int>& nums) {
        int sp=small_pos(nums);
        int ln=large_neg(nums);
        int n=nums.size();
        int pos=(sp==-1)?0:n-sp;
        int neg=(ln==-1)?0:ln+1;
        return max(pos,neg);
    }
};