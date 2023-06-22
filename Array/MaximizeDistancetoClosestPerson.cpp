//https://leetcode.com/problems/maximize-distance-to-closest-person/

//TC:O(3N)//SC:O(2N)
int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();
        vector<int> lc(n,0);
        vector<int> rc(n,0);
        
        lc[0]=seats[0]==1?0:INT_MAX;
        for(int i=1;i<n;i++)
        {
            lc[i]=seats[i]==1?i:lc[i-1];
        }
        rc[n-1]=seats[n-1]==1?n-1:INT_MAX;
        for(int i=n-2;i>=0;i--)
        {
            rc[i]=seats[i]==1?i:rc[i+1];
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int cpd=min(abs(i-lc[i]),abs(rc[i]-i));
            ans=max(ans,cpd);
        }
        return ans;
    }

//TC:O(N)//SC:O(1)
//Edge Cases: 1. 0th element is 0   2.last element is zero      
//Intuition: Alex should sit in the middle of two persons to increase the distFromClosestPerson except for edge cases
int maxDistToClosest(vector<int>& seats) {
        seats.push_back(1);
        int prev=-1,n=seats.size(),ans=INT_MIN;
        for(int cur=0;cur<n;cur++)
        {
            if(seats[cur]==1)
            {
                int noofzeros=cur-prev-1;
                if(prev==-1 || cur==n-1)    //For Handling Edge Cases
                {
                    ans=max(ans,noofzeros);
                }
                else        
                {
                    int distFromClosestPerson=(noofzeros+1)/2;
                    ans=max(ans,distFromClosestPerson);
                }
                prev=cur;
            }
        }
        return ans;
    }