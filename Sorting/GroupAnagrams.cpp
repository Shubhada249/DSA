//https://leetcode.com/problems/group-anagrams/

//TC:O(100*n^2)     //SC:O(200+n)
bool isAnagram(string str,string st)
{
    if(str.size()!=st.size())
        return false;
    unordered_map<char,int> mp;     //O(200)
    for(int i=0,j=0;i<str.size();i++,j++)
    {
        mp[str[i]]++;
        mp[st[j]]--;
    }
    for(auto it:mp)
    {
        if(it.second!=0)
            return false;
    }
    return true;
}
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    int n=strs.size();
    vector<bool> visit(n,false);    //O(n)
        vector<vector<string>> ans;
    for(int i=0;i<n;i++)        //O(n^2)
    {
        if(visit[i])
            continue;
        visit[i]=true;
        vector<string> temp;
        temp.push_back(strs[i]);
        for(int j=i+1;j<n;j++)
        {
            if(visit[j])
                continue;
            bool ch=isAnagram(strs[i],strs[j]);     //O(100)
            if(ch)
            {
                visit[j]=true;
                temp.push_back(strs[j]);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}


//TC:O(200n +n)     //SC:O(n)
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    int n=strs.size();
    vector<vector<string>> ans;
    unordered_map<string,vector<string>> mp;    //O(n)
    for(int i=0;i<n;i++)        //O(200n)
    {
        string wrd=strs[i];
        string swrd=wrd;
        sort(swrd.begin(),swrd.end());
        mp[swrd].push_back(strs[i]);
    }
    for(auto it:mp)     //O(n)
    {
        ans.push_back(it.second);
    }
    return ans;
}