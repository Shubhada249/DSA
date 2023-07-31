//https://leetcode.com/problems/basic-calculator-ii/

//Optimisation Note: 1. add rec to ans when operator is + or -
//                   2. you just need top of stack and you dont need all numbers in stack. So store top of stack as rec.
//TC:O(n)   //SC:O(n)
int calculate(string s) {
        stack<int> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='*')
            {
                int f=st.top();
                st.pop();                
                i++;
                while(i<s.size() && s[i]==' ')
                {
                    i++;
                }
                string str="";
                while(i<s.size() && isdigit(s[i]))
                {
                    str=str+s[i];
                    i++;
                }
                i--;
                st.push(f*stoi(str));
            }
            else if(s[i]=='/')
            {
                double f=st.top();
                st.pop();                
                i++;
                while(i<s.size() && s[i]==' ')
                {
                    i++;
                }
                string str="";
                while(i<s.size() && isdigit(s[i]))
                {
                    str=str+s[i];
                    i++;
                }
                i--;
                st.push(f/stoi(str));
            }
            else if(s[i]=='+' || s[i]==' ')
            {
                continue;
            }
            else if(s[i]=='-')
            {
                i++;
                while(i<s.size() && s[i]==' ')
                {
                    i++;
                }
                string str="";
                while(i<s.size() && isdigit(s[i]))
                {
                    str=str+s[i];
                    i++;
                }
                i--;
                st.push(0-stoi(str));
            }
            else
            {
                string str="";
                while(i<s.size() && isdigit(s[i]))
                {
                    str=str+s[i];
                    i++;
                }
                i--;
                
                st.push(stoi(str));
            }
        }
        int ans=0;
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }

//TC:O(n)   //SC:O(1)
int calculate(string s) {
        stack<int> st;
        int rec=0,ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
                continue;
            else if(s[i]=='*')
            {
                int f=rec;             
                i++;
                while(i<s.size() && s[i]==' ')
                {
                    i++;
                }
                string str="";
                while(i<s.size() && isdigit(s[i]))
                {
                    str=str+s[i];
                    i++;
                }
                i--;
                rec=(f*stoi(str));
            }
            else if(s[i]=='/')
            {
                int f=rec;               
                i++;
                while(i<s.size() && s[i]==' ')
                {
                    i++;
                }
                string str="";
                while(i<s.size() && isdigit(s[i]))
                {
                    str=str+s[i];
                    i++;
                }
                i--;
                rec=(f/stoi(str));
            }
            else if(s[i]=='+')
            {
                ans+=rec;
            }
            else if(s[i]=='-')
            {
                ans+=rec;
                
                i++;
                while(i<s.size() && s[i]==' ')
                {
                    i++;
                }
                string str="";
                while(i<s.size() && isdigit(s[i]))
                {
                    str=str+s[i];
                    i++;
                }
                i--;
                rec=(0-stoi(str));
            }
            else
            {
                string str="";
                while(i<s.size() && isdigit(s[i]))
                {
                    str=str+s[i];
                    i++;
                }
                i--;
                
                rec=(stoi(str));
            }
        }
        ans+=rec;
        return ans;
    }