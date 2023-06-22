//https://leetcode.com/problems/count-and-say/

string countAndSay(int n) {
        string prev="", cur="";
        for(int i=1;i<=n;i++)
        {
            cur="";
            if(i==1)
                cur="1";
            else
            {
                int j=0;
                int sz=prev.size();
                while(j<sz)
                {
                    char c=prev[j];
                    int count=0;
                    while(j<sz && prev[j]==c)
                    {
                        count++;
                        j++;
                    }
                    cur=cur+to_string(count)+c;
                }
            }
            prev=cur;
        }
        return cur;
    }