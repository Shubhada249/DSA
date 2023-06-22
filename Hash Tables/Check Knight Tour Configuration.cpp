//https://leetcode.com/problems/check-knight-tour-configuration/

//TC:O(n^2)     //SC:O(n^2)
//Edge Case: grid[0][0]!=0
bool fun(int r1,int v1,int r2,int v2)
    {
        int vd=abs(r1-r2);
        int hd=abs(v1-v2);
        return ((vd==1 && hd==2)||(vd==2 && hd==1));

    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0]!=0)
            return false;
        
        map<int,pair<int,int>> mp;
        int n=grid.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                mp[grid[i][j]]={i,j};
            }
        }
 
        for(int i=0;i<n*n-1;i++)
        {
            bool ch=fun(mp[i].first,mp[i].second,mp[i+1].first,mp[i+1].second);
            if(ch==false)
            {
                return false;
            }
        }
        return true;
    }