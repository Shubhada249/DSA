//https://leetcode.com/problems/product-of-array-except-self/

//TC:O(3n)  //SC:O(1)
vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++)    //prefix product in ans
        {
            if(i==0)
                ans[i]=1;
            else
            {
                ans[i]=ans[i-1]*nums[i-1];
            }
        }
        
        int p1,p2=nums[n-1];
        nums[n-1]=1;
        for(int i=n-2;i>=0;i--)     //suffix product in nums
        {
            p1=p2;
            p2=nums[i];
            nums[i]=nums[i+1]*p1;                
        }
        for(int i=0;i<n;i++)    //ans=prefix*suffix
        {
            ans[i]=ans[i]*nums[i];
        }
        return ans;
    }