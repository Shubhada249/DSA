//https://leetcode.com/problems/find-and-replace-pattern/

//TC:O(n*k)     //SC:O(n*k)     //where N is the number of words, and K is the length of each word.
string fun(string str)
    {
        string ans="";
        int n=1;
        unordered_map<char,int> mp;
        for(int i=0;i<str.size();i++)
        {
            if(mp.find(str[i])==mp.end())
            {
                mp[str[i]]=n;
                n++;
            }
            ans=ans+to_string(mp[str[i]])+",";                
        }
        return ans;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        string pat=fun(pattern);
        for(int i=0;i<words.size();i++)
        {
            string st=fun(words[i]);
            if(st==pat)
                ans.push_back(words[i]);
        }
        return ans;
    }