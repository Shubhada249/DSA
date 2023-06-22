//https://leetcode.com/problems/single-number-ii/

//TC:O(n)   //SC:O(n)
int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        for(auto it:mp)
        {
            if(it.second!=3)
                return it.first;
        }
        return 0;
    }

//TC:O(32n)   //SC:O(1)
int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int c=0;
        int ans=0;
        while(c<32)
        {
            int count=0;
            for(int i=0;i<n;i++)
            {
                if((1 & nums[i])==1)
                    count++;
                nums[i]=nums[i]>>1;
            }
            
            if(count%3==1)
                ans=(ans|(1<<c));
            c++;
        }
        return ans;
    }


//TC:O(n)   //SC:O(1)
int singleNumber(vector<int>& nums) {
        int s3n=~0,s3np1=0,s3np2=0;
        int s3nan,s3np1an,s3np2an;
        
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            s3nan=(s3n & nums[i]);
            s3np1an=(s3np1 & nums[i]);
            s3np2an=(s3np2 & nums[i]);
            
            s3n=(~s3nan)&s3n;
            s3np1=s3np1 | s3nan;
            
            s3np1=(~s3np1an)&s3np1;
            s3np2=s3np2 | s3np1an;
            
            s3np2=(~s3np2an)&s3np2;
            s3n=s3n | s3np2an;
        }
        return s3np1;
    }