//https://leetcode.com/problems/evaluate-reverse-polish-notation/

//TC:O(n)   //SC:O(n)
int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n=tokens.size();
        for(int i=0;i<n;i++)
        {
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/")
            {
                int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();
                if(tokens[i]=="+")
                    st.push(a+b);
                else if(tokens[i]=="-")
                    st.push(a-b);
                else if(tokens[i]=="*")
                    st.push(a*b);
                else
                    st.push(a/b);
            }
            else
                st.push(stoi(tokens[i]));
        }
        return st.top();
    }

//TC:O(n)   //SC:O(1)
int evalRPN(vector<string>& tokens) {
    int n=tokens.size(),top=0;
    
    for(int i=0;i<n;i++)
    {
        if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/")
        {
            top--;              
            int b=stoi(tokens[top]);
            top--;
            int a=stoi(tokens[top]);
            if(tokens[i]=="+")
                tokens[top]=to_string(a+b);
            else if(tokens[i]=="-")
                tokens[top]=to_string(a-b);
            else if(tokens[i]=="*")
                tokens[top]=to_string(a*b);
            else
                tokens[top]=to_string(a/b);
            top++;
        }
        else
            tokens[top++]=tokens[i];
    }
    return stoi(tokens[--top]);
}