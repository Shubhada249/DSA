//https://leetcode.com/problems/remove-outermost-parentheses/

//TC:O(n)   //SC:O(n)
string removeOuterParentheses(string s) {
        stack<int> st;
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                if(st.size()!=0)
                    ans=ans+s[i];
                st.push(i);                
            }
            else
            {
                if(st.size()!=1)
                    ans=ans+s[i];
                st.pop();
            }
        }
        return ans;
    }

//TC:O(n)   //SC:O(1)
string removeOuterParentheses(string s) {
        int cnt=0;
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                if(cnt!=0)
                    ans=ans+s[i];
                cnt++;                
            }
            else
            {
                if(cnt!=1)
                    ans=ans+s[i];
                cnt--;
            }
        }
        return ans;
    }