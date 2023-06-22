//https://leetcode.com/problems/valid-palindrome/

//TC:O(3N)//SC:O(1)
bool isPalindrome(string s) {
        for(int i=0;i<s.size();i++)
        {
            if(!iswalnum(s[i]))
            {
                s.erase(i,1);
                i--;    //IMP
            }
        }
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for(int i=0,j=s.size()-1;i<j;i++,j--)
        {
            if(s[i]!=s[j])
                return false;
        }
        return true;
            
    }

//TC:O(N)//SC:O(1)
bool isPalindrome(string s) {
        for(int i=0,j=s.size()-1;i<j;i++,j--)
        {
            while(i<j && !iswalnum(s[i]))
            {
                i++;
            }
            while(i<j && !iswalnum(s[j]))
            {
                j--;
            }
            if(i<j && tolower(s[i])!=tolower(s[j]))
                return false;
        }
        return true;
    }

//TC:O(3N)//SC:O(N)
bool fun(string &s,int i,int j)
{
    if(i>=j)
        return true;
    while(i<j && !iswalnum(s[i]))
        i++;
    while(i<j && !iswalnum(s[j]))
        j--;
    if(tolower(s[i])!=tolower(s[j]))
        return false;
    return fun(s,i+1,j-1);
}
bool isPalindrome(string s) {
    
    return fun(s,0,s.size()-1);
}