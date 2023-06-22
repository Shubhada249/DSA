//https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/

//TC:O(n^2)     //SC:O(1)
int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n=nums.size(),i1=0,j1=firstLen-1,sum1=accumulate(nums.begin(),nums.begin()+j1,0),ans=0,sum2;
        for(;j1<n;j1++,i1++)
        {
            sum1+=nums[j1];
            if(secondLen-1<i1)
                sum2=accumulate(nums.begin()+0,nums.begin()+secondLen-1,0);
            for(int i2=0,j2=secondLen-1;j2<i1;i2++,j2++)
            {
                sum2+=nums[j2];
                //cout<<sum1<<" "<<sum2<<"\n";
                ans=max(ans,sum1+sum2);
                sum2-=nums[i2];
            }
            if(j1+secondLen<n)
                sum2=accumulate(nums.begin()+j1+1,nums.begin()+j1+secondLen,0);
            for(int i2=j1+1,j2=j1+secondLen;j2<n;i2++,j2++)
            {
                sum2+=nums[j2];
                //cout<<sum1<<" "<<sum2<<"\n";
                ans=max(ans,sum1+sum2);
                sum2-=nums[i2];
            }
            sum1-=nums[i1];
        }
        return ans;
    }


//TC:O(n)   //SC:O(n)
int fun(int n1,int n2,vector<int>& nums)
    {
        int n=nums.size();
        vector<int> vec1(n,0),vec2(n,0);
        int i=0,j=0,sum=0;
        while(j<n)
        {
            sum+=nums[j];
            if(j-i+1<n1)
                j++;
            else if(j-i+1==n1)
            {   
                if(j-1>=0)
                    vec1[j]=max(vec1[j-1],sum);
                else
                    vec1[j]=sum;
                sum-=nums[i];
                i++;
                j++;
            }
        }
        
        i=n-1;
        j=n-1;
        sum=0;
        while(j>=0)
        {
            sum+=nums[j];
            if(i-j+1<n2)
                j--;
            else if(i-j+1==n2)
            {
                if(j+1<n)
                    vec2[j]=max(vec2[j+1],sum);
                else
                    vec2[j]=sum;
                
                sum-=nums[i];
                i--;
                j--;
            }
        }
        int ans=0;
        for(i=n1-1;i<n-n2;i++)
        {
            ans=max(ans,vec1[i]+vec2[i+1]);
        }
        // for(i=0;i<n;i++)
        // {
        //     cout<<vec1[i]<<" ";
        // }
        // cout<<"\n";
        // for(i=0;i<n;i++)
        // {
        //     cout<<vec2[i]<<" ";
        // }
        // cout<<"\n\n";
        return ans;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n=nums.size();
        return max(fun(firstLen,secondLen,nums),fun(secondLen,firstLen,nums));
    }