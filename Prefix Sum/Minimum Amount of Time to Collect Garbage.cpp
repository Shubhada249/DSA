//https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/

//TC:O(10^6 + 10^5)     //SC:O(1)
int garbageCollection(vector<string>& garbage, vector<int>& travel) {
    int n=garbage.size(),gi=0,pi=0,mi=0,gc=0,pc=0,mc=0;
    for(int i=0;i<n;i++)        //TC:O(10^6)
    {
        for(int j=0;j<garbage[i].size();j++)
        {
            if(garbage[i][j]=='G')
            {
                gc++;
                gi=i;
            }
            else if(garbage[i][j]=='P')
            {
                pc++;
                pi=i;
            }
            else
            {
                mc++;
                mi=i;
            }
        }
    }
    int t=gc+pc+mc;
    for(int i=1;i<n;i++)    //TC:O(10^5)
    {
        int count=0;
        if(gi>=i)
            count++;
        if(pi>=i)
            count++;
        if(mi>=i)
            count++;
        t+=count*travel[i-1];            
    }
    return t;
}

//TC:O(10^6 + 10^5)     //SC:O(1)
int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n=garbage.size(),gi=0,pi=0,mi=0,ans=0;
        for(int i=0;i<n;i++)        //TC:O(10^6)
        {
            for(int j=0;j<garbage[i].size();j++)
            {
                ans++;
                if(garbage[i][j]=='G')
                    gi=i;
                
                else if(garbage[i][j]=='P')
                    pi=i;
                
                else
                    mi=i;
            }
        }
        
        for(int i=1;i<n-1;i++)  //O(10^5)
        {
            travel[i]+=travel[i-1];
        }
        if(mi>0)
            ans+=travel[mi-1];    
        if(gi>0)
            ans+=travel[gi-1]; 
        if(pi>0)
            ans+=travel[pi-1]; 
        return ans;
    }