//https://leetcode.com/problems/removing-stars-from-a-string/

//TC:O(n)       //SC:O(n)
string removeStars(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='*')
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        string ans="";
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }


string removeStars(string s) {
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='*')
            {
                j--;
            }
            else
            {
                s[j]=s[i];
                j++;
            }
        }
        
        return s.substr(0,j);
    }