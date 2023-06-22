//https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/

//TC:O(n)   //SC:O(1)
int minimumRecolors(string blocks, int k) {
        int i=0,j=0,n=blocks.size(),wc=0,bc=0,res=INT_MAX;
        while(j<n)
        {
            if(blocks[j]=='W')
                wc++;
            else
                bc++;
            
            if(j-i+1<k)
                j++;
            else if(j-i+1==k)
            {
                res=min(res,wc);
                if(blocks[i]=='W')
                    wc--;
                else
                    bc--;
                i++;
                j++;
            }
        }
        return res;
    }