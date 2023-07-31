//https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/

//TC:O(1)   //SC:O(1)
int minimumSum(int num) {
        string str=to_string(num);
        sort(str.begin(),str.end());
        string r="",t="";
        r.push_back(str[0]);
        r.push_back(str[2]);
        t.push_back(str[1]);
        t.push_back(str[3]);
        int p=stoi(r);
        int q=stoi(t);
        return p+q;
    }