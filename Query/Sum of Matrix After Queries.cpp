//https://leetcode.com/problems/sum-of-matrix-after-queries/

//TC(O(s))      //SC:O(2n)
long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        int r=0,c=0,s=queries.size();
        long long a,ans=0;
        vector<bool> visitr(n,false),visitc(n,false);
        for(int i=s-1;i>=0;i--)
        {   
            a=0;
            if(visitc[queries[i][1]]==false && queries[i][0]==1)
            {
                    a=(long long)((n-r)*queries[i][2]);
                    c++;
                    visitc[queries[i][1]]=true;
            }
            else if( visitr[queries[i][1]]==false &&  queries[i][0]==0)
            {
                    a=(long long)((n-c)*queries[i][2]);
                    r++;
                    visitr[queries[i][1]]=true;
            }
            ans+=a;
        }
        return ans;
    }