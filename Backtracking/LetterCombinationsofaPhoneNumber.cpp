//https://leetcode.com/problems/letter-combinations-of-a-phone-number/

//TC:O(4^n)     //SC:O(n)
void fun(int ip,string op,string digits,vector<string> &ans,unordered_map<char,string> &mp)
{
    if(ip==digits.size())
    {
        ans.push_back(op);
        return;
    }
    string str=mp[digits[ip]];
    for(int i=0;i<str.size();i++)
    {
        fun(ip+1,op+str[i],digits,ans,mp);
    }
}
vector<string> letterCombinations(string digits) {
    vector<string> ans;
    unordered_map<char,string> mp={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    if(digits.size()==0)
        return {};
    fun(0,"",digits,ans,mp);
    return ans;
}