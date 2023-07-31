//https://leetcode.com/problems/crawler-log-folder/

//TC:O(n)   //SC:O(n)
int minOperations(vector<string>& logs) {
        stack<string> st;
        for(int i=0;i<logs.size();i++)
        {
            if(logs[i]=="../")
            {
                if(!st.empty())
                    st.pop();
            }
            else if(logs[i]=="./")
            {
                continue;
            }
            else
            {
                st.push(logs[i]);
            }
        }
        return st.size();
    }

//TC:O(n)   //SC:O(1)
int minOperations(vector<string>& logs) {
        int cnt=0;
        for(int i=0;i<logs.size();i++)
        {
            if(logs[i]=="../")
            {
                if(cnt)
                    cnt--;
            }
            else if(logs[i]=="./")
            {
                continue;
            }
            else
            {
                cnt++;
            }
        }
        return cnt;
    }