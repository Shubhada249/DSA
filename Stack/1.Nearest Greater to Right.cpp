//https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//TC:O(2n)      //SC:O(n)
vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long> ans(n,-1);
        stack<long long> st;
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=arr[i])
                st.pop();
            if(!st.empty())
                ans[i]=st.top();
            st.push(arr[i]);
        }
        return ans;
    }