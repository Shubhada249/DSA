//https://leetcode.com/problems/count-the-number-of-consistent-strings/

//Note: HashTable->bool vector->variable

//TC:O(10^5)    //SC:O(26)
int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int> mp;
        int s=allowed.size();
        int n=words.size();
        for(int i=0;i<s;i++)
        {
            mp[allowed[i]]++;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            bool ch=true;
            for(int j=0;j<words[i].size();j++)
            {
                if(mp.find(words[i][j])==mp.end())
                {
                    ch=false;
                    break;
                }
            }
            if(ch==true)
                ans++;
        }
        return ans;
    }

//TC:O(10^5)    //SC:O(26)
int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> mp(26,false);
        int s=allowed.size();
        int n=words.size();
        for(int i=0;i<s;i++)
        {
            mp[allowed[i]-'a']=true;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            bool ch=true;
            for(int j=0;j<words[i].size();j++)
            {
                if(mp[words[i][j]-'a']==false)
                {
                    ch=false;
                    break;
                }
            }
            if(ch==true)
                ans++;
        }
        return ans;
    }

//TC:O(10^5)    //SC:O(1)
int countConsistentStrings(string allowed, vector<string>& words) {
        int mp=0;
        int s=allowed.size();
        int n=words.size();
        for(int i=0;i<s;i++)
        {
            mp=(mp |(1<<(allowed[i]-'a')));
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            bool ch=true;
            for(int j=0;j<words[i].size();j++)
            {
                if((mp & (1<<(words[i][j]-'a')))==0)
                {
                    ch=false;
                    break;
                }
            }
            if(ch==true)
                ans++;
        }
        return ans;
    }