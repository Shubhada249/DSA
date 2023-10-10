//https://leetcode.com/problems/longest-common-prefix/
//TC:O(n log n+m)     //SC:O(1)
string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        sort(strs.begin(),strs.end());
        string f=strs[0],s=strs[strs.size()-1];
        int i=0;
        while(i<f.size() && i<s.size() && f[i]==s[i])
            ans.push_back(f[i++]);
        return ans;
    }