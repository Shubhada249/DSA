//https://leetcode.com/problems/left-and-right-sum-differences/

//TC:O(3n)    //SC:O(2n)
vector<int> leftRigthDifference(vector<int>& nums) {
    int n=nums.size();       
    vector<int> left(n,0);
    for(int i=1;i<n;i++)
    {
        left[i]=left[i-1]+nums[i-1];
    }
    
    vector<int> right(n,0);
    for(int i=n-2;i>=0;i--)
    {
        right[i]=right[i+1]+nums[i+1];
    }
    
    vector<int> ans(n,0);
    for(int i=0;i<n;i++)
    {
        ans[i]=abs(left[i]-right[i]);
    }
    return ans;
}

//TC:O(3n)    //SC:O(1)
vector<int> leftRigthDifference(vector<int>& nums) {
    int n=nums.size();
    if(n==1)
            return {0};
    vector<int> ans(n,0);
    for(int i=1;i<n;i++)
    {
        ans[i]=ans[i-1]+nums[i-1];
    }
    int p1=nums[n-1],p2=nums[n-2];
    nums[n-1]=0;
    for(int i=n-2;i>=0;i--)
    {
        nums[i]=nums[i+1]+p1;
        p1=p2;
        if(i!=0)
            p2=nums[i-1];
    }
    
    for(int i=0;i<n;i++)
    {
        ans[i]=abs(nums[i]-ans[i]);
    }
    return ans;
}

//TC:O(2n)    //SC:O(1)
vector<int> leftRigthDifference(vector<int>& nums) {
    int n=nums.size();
    int rsum=0,lsum=0;
    for(int i=0;i<n;i++)
    {
        rsum+=nums[i];
    }
    vector<int> ans(n,0);
    for(int i=0;i<n;i++)
    {
        rsum=rsum-nums[i];
        ans[i]=abs(rsum-lsum);
        lsum=lsum+nums[i];
    }
    return ans;
}