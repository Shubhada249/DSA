//https://leetcode.com/problems/roman-to-integer/

//TC:O(n)   //SC:O(n)
int romanToInt(string s) {
        unordered_map<char,int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        int ans=0,n=s.size();
        for(int i=0;i<n;i++)
        {
            if(i+1<n && s[i]=='I' && (s[i+1]=='V' || s[i+1]=='X'))
                ans+=(0-mp[s[i]]);
            
            else if(i+1<n && s[i]=='X' && (s[i+1]=='L' || s[i+1]=='C'))
                ans+=(0-mp[s[i]]);
            
            else if(i+1<n && s[i]=='C' && (s[i+1]=='D' || s[i+1]=='M'))
                ans+=(0-mp[s[i]]);
            
            else
                ans+=(mp[s[i]]);
        }
        return ans;
    }

//TC:O(n)   //SC:O(n)
    int romanToInt(string s) {
        unordered_map<char,int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        int ans=0,n=s.size();
        for(int i=0;i<n-1;i++)  
        {
            if(mp[s[i]]>=mp[s[i+1]])    //Roman numerals are usually written largest to smallest from left to right.
                ans+=mp[s[i]];
            else                        //4,9,40,90,400,900
                ans+=(0-mp[s[i]]);
        }
        ans+=mp[s[n-1]];
        return ans;
    }