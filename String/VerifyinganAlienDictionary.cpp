//https://leetcode.com/problems/verifying-an-alien-dictionary/

//TC:O(total of No.of characters in all words)  //SC:O(26)~O(1)
bool fun(string &a,string &b,unordered_map<char,int> &mp)
    {
        int i=0,j=0,an=a.size(),bn=b.size();
        while(i<an && j<bn)
        {
            int ind1=mp[a[i]];
            int ind2=mp[b[i]];
            if(ind1>ind2)
                return false;
            else if(ind1<ind2)
                return true;
            else
            {
                i++;
                j++;
            }
        }
        if(i==an && j==bn)
            return true;
        if(j==bn)
            return false;
        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> mp;
        for(int i=0;i<order.size();i++) //O(26)
        {
            mp[order[i]]=i;
        }
        
        for(int i=0;i<words.size()-1;i++)   //O(total of No.of characters in all words)
        {
            if(!fun(words[i],words[i+1],mp))
                return false;
        }
        return true;
    }