//

//TC:O(2n)      //SC:O(n)
vector<long long> nextLargerToLoeft(vector<long long> arr, int n){
        // Your code here
        vector<long long> ans(n,-1);
        stack<long long> st;
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && st.top()<=arr[i])
                st.pop();
            if(!st.empty())
                ans[i]=st.top();
            st.push(arr[i]);
        }
        return ans;
    }