 //https://leetcode.com/problems/valid-anagram/

//TC:O(2N log N)    //SC:O(1)
 bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s.size()!=t.size())
            return false;
        for(int i=0,j=0;i<s.size();i++,j++)
        {
            if(s[i]!=t[j])
                return false;
        }
        return true;
    }

//TC:O(3N)  //SC:O(2N)
 bool isAnagram(string s, string t) {
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        
        for(int i=0;i<s.size();i++)
        {
            mp1[s[i]]++;
        }
        for(int i=0;i<t.size();i++)
        {
            mp2[t[i]]++;
        }
        
        if(mp1.size()!=mp2.size())
            return false;
        for(auto it:mp1)
        {
            auto f=mp2.find(it.first);
            if(f!=mp2.end())
            {
                if(it.second!=f->second)
                {                   
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        return true;
    }

//TC:O(2N)  //SC:O(N)
bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        unordered_map<char,int> mp1;
        
        
        for(int i=0;i<s.size();i++)
        {
            mp1[s[i]]++;
            mp1[t[i]]--;
        }
        
        for(auto it:mp1)
        {
            if(it.second!=0)
                return false;
        }
        return true;
    }