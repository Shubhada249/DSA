//https://leetcode.com/problems/largest-rectangle-in-histogram/

//TC:O(n)   //SC:O(n)
int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st1,st2;
        vector<int> l(n,-1),r(n,n),w(n,0);
        for(int i=0;i<n;i++)
        {
            while(!st1.empty() && heights[st1.top()]>=heights[i])
                st1.pop();
            if(!st1.empty())
                l[i]=st1.top();
            st1.push(i);
        }
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st2.empty() && heights[st2.top()]>=heights[i])
                st2.pop();
            if(!st2.empty())
                r[i]=st2.top();
            st2.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            w[i]=r[i]-l[i]-1;
            ans=max(ans,w[i]*heights[i]);
        }
        return ans;
    }