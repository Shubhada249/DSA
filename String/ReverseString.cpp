//https://leetcode.com/problems/reverse-string/

//TC:O(n)   //SC:O(1)
void reverseString(vector<char>& s) {
        reverse(s.begin(),s.end());
    }

//TC:O(n)   //SC:O(1)
void reverseString(vector<char>& s) {
        int n=s.size();
        for(int i=0,j=n-1;i<j;i++,j--)
        {
            swap(s[i],s[j]);
        }
    }