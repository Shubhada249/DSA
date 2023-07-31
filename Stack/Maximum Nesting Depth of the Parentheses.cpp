//https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

//TC:O(n)   //SC:O(n)
int maxDepth(string s) {
        stack <char> st;
        int maxi=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                st.push('(');
            else if(s[i]==')')
            {
                maxi=max(maxi,(int)st.size());
                st.pop();
            }
        }
        return maxi;
    }

//TC:O(n)   //SC:O(1)
int maxDepth(string s) {
        int maxi=0,cnt=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                cnt++;
            else if(s[i]==')')
                cnt--;
            maxi=max(maxi,cnt);
        }
        return maxi;
    }