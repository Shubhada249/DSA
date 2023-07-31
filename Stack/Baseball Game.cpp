//https://leetcode.com/problems/baseball-game/

//TC:O(n)   //SC:O(1)
int calPoints(vector<string>& operations) {
        stack<int> st;
        int sum=0;
        for(int i=0;i<operations.size();i++)
        {
            if(operations[i]=="+")
            {
                int f=st.top();
                st.pop();
                int s=st.top();
                st.push(f);
                st.push(f+s);
                sum+=st.top();
            }
            else if(operations[i]=="D")
            {
                st.push(2*st.top());
                sum+=st.top();
            }
            else if(operations[i]=="C")
            {
                sum-=st.top();
                st.pop();
            }
            else
            {
                st.push(stoi(operations[i]));
                sum+=st.top();
            }
        }
        return sum;
    }