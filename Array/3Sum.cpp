//https://leetcode.com/problems/3sum/

//TC:O(n^2)     //SC:O(1)
vector<vector<int>> threeSum(vector<int>& nums) {
    int n=nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    for(int i=0;i<n;i++)
    {
        if(i!=0 && nums[i]==nums[i-1])
            continue;
        int j=i+1,k=n-1;
        
        while(j<k)
        {
            int sum=nums[j]+nums[k];
            if(sum==-nums[i])
            {
                ans.push_back({nums[i],nums[j],nums[k]});
                j++;
                k--;
                while(j<k && nums[j]==nums[j-1])
                    j++;
                    
                while(j<k && nums[k]==nums[k+1])
                    k--;
            }
            else if(sum>-nums[i])
            {
                k--;
                while(j<k && nums[k]==nums[k+1])
                    k--;
            }
            else
            {
                j++;
                while(j<k && nums[j]==nums[j-1])
                    j++;
            }
            
        }
    }
    return ans;
}