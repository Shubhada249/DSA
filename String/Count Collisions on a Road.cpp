//https://leetcode.com/problems/count-collisions-on-a-road/

//TC:O(n)   //SC:O(n)
int countCollisions(string directions) {
        int n=directions.size();
        vector<int> ls(n,0),rs(n,0);
        for(int i=n-2;i>=0;i--)
        {
            if(ls[i+1] || directions[i+1]=='L' || directions[i+1]=='S')
                ls[i]=1;
        }
        for(int i=1;i<n;i++)
        {
            if(rs[i-1] || directions[i-1]=='R' || directions[i-1]=='S')
                rs[i]=1;
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(directions[i]=='L')
            {
                if(rs[i])
                    ans++;
            }
            else if(directions[i]=='R')
            {
                if(ls[i])
                    ans++;
            }
        }
        return ans;
    }

//TC:O(n)   //SC:O(1)
int countCollisions(string directions) {
        int n=directions.size();
        //vector<int> ls(n,0),rs(n,0);
        int ls=-1,rs=n,prev=0;
        for(int i=n-2;i>=0;i--)
        {
            if(directions[i+1]=='L' || directions[i+1]=='S')
            {
                ls=i;
                break;
            }
        }
        for(int i=1;i<n;i++)
        {
            if(directions[i-1]=='R' || directions[i-1]=='S')
            {
                rs=i;
                break;
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(directions[i]=='L')
            {
                if(i>=rs)
                    ans++;
            }
            else if(directions[i]=='R')
            {
                if(i<=ls)
                    ans++;
            }
        }
        return ans;
    }

//TC:O(n)   //SC:O(1)
int countCollisions(string directions) {
        int n=directions.size(),l=0,r=n-1;
        while(l<n && directions[l]=='L')
            l++;
        while(r>=0 && directions[r]=='R')
            r--;
        int ans=0;
        for(int i=l;i<=r;i++)
        {
            if(directions[i]!='S')
                ans++;
        }
        return ans;
    }