//https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/

//TC:O(more than n)     //SC:O(1)
int numSteps(string s) {
        int steps=0;
        while(s!="1")
        {
            int n=s.size();
            if(s[n-1]=='0')
            {
                s.erase(n-1,1);
                steps++;
            }
            else
            {
                int i=n-1;
                while(i>=0 && s[i]=='1')
                {
                    //s.replace(i,1,"0");
                    s[i]='0';
                    i--;
                }
                if(i!=-1)
                    s[i]='1';//s.replace(i,1,"1");
                else
                    s.insert(0,"1");
                steps++;
            }
        }
        return steps;
    }

//TC:O(n)   //SC:O(1)
int numSteps(string s) {
        int steps=0;
        int i=s.size()-1;
        while(i>0 && s[i]=='0')
        {
            steps++;
            i--;
        }
        if(i==0)
            return steps;
        if(i>0 && s[i]=='1')
        {
            steps+=2;
            i--;
        }
        while(i>=0)
        {
            if(s[i]=='0')
                steps+=2;
            else
                steps++;
            i--;
        }
        
        return steps;
    }