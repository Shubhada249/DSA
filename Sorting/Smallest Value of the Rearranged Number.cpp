//https://leetcode.com/problems/smallest-value-of-the-rearranged-number/

//TC:O(n log n+n)     //SC:O(n)
long long smallestNumber(long long num) {
        if(num==0)
            return num;
        else if(num<0)
        {
            num=0-num;
            string str=to_string(num);
            sort(str.begin(),str.end(),greater<int>());
            num=stoll(str);
            return 0-num;
        }
        else
        {
            string str=to_string(num);
            sort(str.begin(),str.end());
            int i=0;
            while(i<str.size() && str[i]=='0')
                i++;
            char d=str[i];
            str.erase(i,1);
            str=d+str;    
            num=stoll(str);
            return num;
        }
        return num;
    }