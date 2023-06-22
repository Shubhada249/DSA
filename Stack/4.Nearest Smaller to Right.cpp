
//TC:O(2n)      //SC:O(n)
vector<int> rightSmaller(int n, int a[]){
        // code here
        vector<int> ans(n,-1);
        stack<int> st;
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()>=a[i])
                st.pop();
            if(!st.empty())
                ans[i]=st.top();
            st.push(a[i]);
        }
        return ans;
    }