//https://leetcode.com/problems/valid-palindrome-ii/

//TC:O(n)   //SC:O(1)
bool fun(string s)
    {
        int n=s.size();
        int i=0,j=n-1;
        while(i<j && s[i]==s[j])
        {
            i++;
            j--;
        }
        if(i>=j)
            return true;
        return false;
    }
    bool validPalindrome(string s) {
        int n=s.size();
        int i=0,j=n-1;
        while(i<j && s[i]==s[j])
        {
            i++;
            j--;
        }
        if(i>=j)
            return true;
        bool f=fun(s.substr(i,j-i));
        bool sec=fun(s.substr(i+1,j-i));
        //cout<<f<<" "<<sec;
        return ( f|| sec);
    }