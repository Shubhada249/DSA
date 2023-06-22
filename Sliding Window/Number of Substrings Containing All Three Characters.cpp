//https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

//TC:O(n)   //SC:O(1)
int numberOfSubstrings(string s) {
        int i=0,j=0,n=s.size(),a=0,b=0,c=0,unique=0,ans=0;
        while(j<n)
        {
            if(s[j]=='a')
            {
                a++;
                if(a==1)
                    unique++;
            }
            else if(s[j]=='b')
            {
                b++;
                if(b==1)
                    unique++;
            }
            else
            {
                c++;
                if(c==1)
                    unique++;
            }
            
            if(unique<3)
                j++;
            else if(unique==3)
            {
                while(i<n && unique==3)
                {
                    ans+=n-j;
                    if(s[i]=='a')
                    {
                        a--;
                        if(a==0)
                            unique--;
                    }
                    else if(s[i]=='b')
                    {
                        b--;
                        if(b==0)
                            unique--;
                    }
                    else
                    {
                        c--;
                        if(c==0)
                            unique--;
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
    }