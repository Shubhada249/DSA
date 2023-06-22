//https://leetcode.com/problems/plus-one/

//TC:O(n)   //SC:O(1)
vector<int> plusOne(vector<int>& digits) {
        int carry=1,n=digits.size();
        for(int i=n-1;i>=0 && carry;i--)
        {
            int ele=digits[i]+1;
            if(ele==10)
            {
                carry=true;
                digits[i]=0;
            }
            else
            {
                carry=false;
                digits[i]++;
                return digits;
            }
        }
        if(carry)
            digits.insert(digits.begin(),1);
        return digits;
    }