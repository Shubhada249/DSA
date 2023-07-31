//https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

//TC:O(n log n)     //SC:O(1)
static bool ShouldISwap(vector<int> &a,vector<int> &b)
    {
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),ShouldISwap);
        int ele=points[0][1],ans=0,i=1,last=0,n=points.size();
        while(i<n)
        {
            while(i<n && ele>=points[i][0] && ele<=points[i][1])
                i++;
            ans++;
            if(i<n)
            {   
                ele=points[i][1];
                if(i==n-1)
                    last=n-1;
                i++;
            }
        }
        if(last==n-1)
            ans++;
        return ans;
    }