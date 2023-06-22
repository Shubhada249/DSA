//https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/

//TC:O(m log(max_element from quantities))  //SC:O(1)
int atleastReqStores(int mid,vector<int>& quantities,int m)
    {
        int atleast=0;
        for(int i=0;i<m;i++)
        {
            if(quantities[i]%mid!=0)
                atleast++;
            atleast+=quantities[i]/mid;                
        }
        return atleast;
    }
    
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m=quantities.size();
        int low=1,high=*max_element(quantities.begin(),quantities.end()),ans;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int atleast=atleastReqStores(mid,quantities,m);
            
            if(atleast>n)
                low=mid+1;
            else
            {
               ans=mid;
                high=mid-1;
            }            
        }
        return ans;
    }