//https://leetcode.com/problems/largest-number/

static bool ShouldISwap(string a,string b)
{
    string f=a+b;
    string s=b+a;
    return f>s;
}
string largestNumber(vector<int>& nums) {
    vector<string> vec;
    for(int i=0;i<nums.size();i++)
    {
        vec.push_back(to_string(nums[i]));
    }
    sort(vec.begin(),vec.end(),ShouldISwap);
    string ans="";
    for(int i=0;i<vec.size();i++)
    {
        ans+=vec[i];
    }
    int i=0;
    while(i<ans.size() && ans[i]=='0')
    {
        i++;
    }
    if(i==ans.size())
        return "0";
    return ans.substr(i);
}



static bool ShouldISwap(int a,int b)
{
    string a1=to_string(a);
    string b1=to_string(b);
    return a1+b1>b1+a1;
}
string largestNumber(vector<int>& nums) {
    if(nums[0]==0 && nums[nums.size()-1]==0)
        return "0";
    sort(nums.begin(),nums.end(),ShouldISwap);
    string ans="";
    
    for(int i=0;i<nums.size();i++)
    {
        ans+=to_string(nums[i]);
    }
    return ans;
}