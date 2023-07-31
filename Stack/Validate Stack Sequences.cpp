//https://leetcode.com/problems/validate-stack-sequences/
//TC:O(n)   //SC:O(n)
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n=pushed.size(),i=0,j=0;
        stack<int> st;
        while(j<n)
        {
            if(st.empty() || st.top()!=popped[j])
            {
                if(i<n)
                {
                    st.push(pushed[i]);
                    i++;
                }
                else
                    return false;
            }
            else
            {
                st.pop();
                j++;
            }
        }
        return true;
    }

//TC:O(n)   //SC:O(1)
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n=pushed.size(),i=0,j=0;
        int st=-1;
        while(j<n)
        {
            if(st==-1 || pushed[st]!=popped[j])
            {
                if(i<n)
                {
                    //st.push(pushed[i]);
                    pushed[++st]=pushed[i];
                    i++;
                }
                else
                    return false;
            }
            else
            {
                st--;
                j++;
            }
        }
        return true;
    }