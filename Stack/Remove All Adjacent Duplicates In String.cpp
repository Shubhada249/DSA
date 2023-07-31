//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

//TC:O(n)   //SC:O(n)
string removeDuplicates(string s) {
        stack<char> st;
        
        for(int i=0;i<s.size();i++)
        {
            if(!st.empty() && s[i]==st.top())
                st.pop();
            else
                st.push(s[i]);            
        }
        string ans="";
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }