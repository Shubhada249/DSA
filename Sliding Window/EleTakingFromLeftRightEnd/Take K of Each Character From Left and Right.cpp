//https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/

//TC:O(n)   //SC:O(1)
int takeCharacters(string s, int k) {
        if(k==0)
            return 0;
        int n=s.size(),i=0,j=0,na=0,nb=0,nc=0,count=0,maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a')
            {
                na++;
            }
            else if(s[i]=='b')
            {
                nb++;
            }
            else
            {
                nc++;
            }
        }
        if(na<k || nb<k || nc<k)
            return -1;
        na-=k;
        nb-=k;
        nc-=k;
        while(j<n)
        {
            if(s[j]=='a')
            {
                na--;
            }
            else if(s[j]=='b')
            {
                nb--;
            }
            else
            {
                nc--;
            }
            
            while(na<0 || nb<0 || nc<0)
            {
                if(s[i]=='a')
                {
                    na++;
                }
                else if(s[i]=='b')
                {
                    nb++;
                }
                else
                {
                    nc++;
                }
                i++;
            }
            maxi=max(maxi,j-i+1);
            j++;            
        }
        
        return n-maxi;
    }