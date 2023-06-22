//https://leetcode.com/problems/fraction-to-recurring-decimal/

//Edge Cases:   1.sign of numerator and denominator     2.INT_MIN   3.numerator=0
//TC:O(digits after decimal point)    //SC:O(digits after decimal point)
string fractionToDecimal(int numerator, int denominator) {
    if(numerator==0)
        return "0";
    string ans="";
    if(numerator<0 ^ denominator<0)
        ans+="-";
    ll n=llabs(numerator),d=llabs(denominator);
    ans=ans+to_string(n/d);
    ll rem=n%d;
    if(rem==0)
        return ans;
    ans+=".";
    unordered_map<ll,int> mp;
    while(rem)
    {
        rem*=10;
        if(mp.find(rem)!=mp.end())
        {
            ans+=")";
            ans.insert(mp[rem],"(");
            break;
        }
        mp[rem]=ans.size();
        ans+=to_string(rem/d);
        rem=rem%d;
    }
    return ans;
}