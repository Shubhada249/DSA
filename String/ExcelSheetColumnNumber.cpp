//https://leetcode.com/problems/excel-sheet-column-number/

//TC:O(n)   //SC:O(1)
int titleToNumber(string columnTitle) {     //traversed string from last to first
        int p=1,n=columnTitle.size(),i=n-1;
        long long ans=0;
        ans+=(columnTitle[i]-'A'+1)*p;
        i--;
        while(i>=0)
        {
            p=p*26;
            ans+=(columnTitle[i]-'A'+1)*(p);
            i--;
        }
        return ans;
    }

//TC:O(n)   //SC:O(1)
int titleToNumber(string columnTitle) {     //traversed string from first to last
        int n=columnTitle.size(),ans=0;
        for(int i=0;i<n;i++)
        {
            ans=ans*26+(columnTitle[i]-'A'+1);
        }
        return ans;
    }