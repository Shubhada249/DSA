//https://practice.geeksforgeeks.org/problems/smallest-number-on-left3403/1


//TC:O(2n)      //SC:O(n)
vector<int> leftSmaller(int n, int a[]){
        // code here
        vector<int> ans(n,-1);
        stack<int> st;
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && st.top()>=a[i])
                st.pop();
            if(!st.empty())
                ans[i]=st.top();
            st.push(a[i]);
        }
        return ans;
    }