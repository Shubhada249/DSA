//https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/

//TC:O(n)   //SC:O(n)
int minSwaps(string s) {
        int n=s.size(),j=n-1,ans=0;
        while(j>0 && s[j]==']')
            j--;
        stack<char> st;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='[')
            {
                st.push('[');
            }
            else
            {
                if(st.empty())
                {
                    ans++;
                    s[i]='[';
                    s[j]=']';
                    i--;
                    j--;
                    while(j>0 && s[j]==']')
                        j--;
                }
                else
                    st.pop();
            }
        }
        return ans;
    }

//TC:O(n)   //SC:O(1)
int minSwaps(string s) {
        int n=s.size(),j=n-1,ans=0;
        while(j>0 && s[j]==']')
            j--;
        int st=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='[')
            {
                st++;
            }
            else
            {
                if(st==0)
                {
                    ans++;
                    s[i]='[';
                    s[j]=']';
                    i--;
                    j--;
                    while(j>0 && s[j]==']')
                        j--;
                }
                else
                    st--;
            }
        }
        return ans;
    }