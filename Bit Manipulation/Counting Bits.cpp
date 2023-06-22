//https://leetcode.com/problems/counting-bits/


//TC:O(n log n)   //SC:O(1)
vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        
        for(int i=0;i<n;i++)
        {
            int prev=i;
            int pos=0;
            while((prev&1)!=0)
            {
                prev=prev>>1;
                pos++;
            }
            ans[i+1]=ans[i]-pos+1;
        }
        return ans;
    }

//TC:O(n)   //SC:O(1)
vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        int i,j;
        if(1<=n)
            ans[1]=1;
        if(2<=n)
            ans[2]=1;
        if(3<=n)
            ans[3]=2;
        
        for(int ps=2,pe=3;ps<=n;ps=ps*2,pe=ps*2-1)
        {
            for(i=ps,j=ps*2;i<=pe && j<=n;i++,j++)
            {
                ans[j]=ans[i];
            }
            for(int i=ps;i<=pe && j<=n;i++,j++)
            {
                ans[j]=ans[i]+1;
            }
        }
        return ans;
    }

//TC:O(n)   //SC:O(1)
vector<int> countBits(int n) {
    int i=1;
    vector<int> ans(n+1,0);
    while(i<=n)
    {
        int j=1;
        if((i & (i-1))==0)
        {
            ans[i]=1;
            i++;
        }
        while(i<=n && (i & (i-1))!=0)
        {
            ans[i]=ans[j]+1;
            j++;
            i++;
        }    
    }
    return ans;    
}

//TC:O(n)   //SC:O(1)
vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        for(int i=1;i<=n;i++)
        {
            ans[i]=ans[i/2]+i%2;
        }
        return ans;
    }