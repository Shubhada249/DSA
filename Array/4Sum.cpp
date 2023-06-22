//https://leetcode.com/problems/4sum/

//TC:O(n^3)     //SC:O(1)
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n=nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());  //Imp
    for(int i=0;i<n;i++)
    {
        if(nums[i]>target/4 || nums[n-1]<target/4)  //Imp
            break;
        if(i!=0 && nums[i]==nums[i-1])
            continue;
        for(int j=i+1;j<n;j++)
        {
            if(j!=i+1 && nums[j]==nums[j-1])
                continue;
            long long req=target-(long long)(nums[i]+nums[j]);  //Imp
            int start=j+1,end=n-1;  //Imp
            while(start<end)
            {
                if(nums[start]+nums[end]==req)
                {
                    ans.push_back({nums[i],nums[j],nums[start],nums[end]});
                    start++;
                    end--;
                    while(start<end && nums[start]==nums[start-1])
                        start++;
                    while(start<end && nums[end]==nums[end+1])
                        end--;
                }
                else if(nums[start]+nums[end]>req)
                {
                    end--;
                }
                else
                {
                    start++;
                }
            }
        }
    }
    return ans;
}