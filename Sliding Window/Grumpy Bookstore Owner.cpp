//https://leetcode.com/problems/grumpy-bookstore-owner/

//TC:O(n)   //SC:O(1)
int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int i=0,j=0,n=grumpy.size(),ans=0,sum=0;
        while(j<n)
        {
            if(grumpy[j]==1)
                sum+=customers[j];
            
            if(j-i+1<minutes)
                j++;
            else if(j-i+1==minutes)
            {
                ans=max(ans,sum);
                
                if(grumpy[i]==1)
                sum-=customers[i];
                i++;
                j++;
            }
        }
        for(i=0;i<n;i++)
        {
            if(grumpy[i]==0)
                ans+=customers[i];
        }
        return ans;
    }