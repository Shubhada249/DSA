//https://leetcode.com/problems/decode-xored-array/

//TC:O(n)   //SC:O(1) but not in place 
vector<int> decode(vector<int>& encoded, int first) {
        int n=encoded.size();
        
        vector<int> vec(n+1,first);
        for(int i=1;i<=n;i++)
        {
            vec[i]=vec[i-1]^encoded[i-1];
        }
        return vec;
    }

//TC:O(n)   //SC:O(1) but in place 
vector<int> decode(vector<int>& encoded, int first) {
        int n=encoded.size();
        encoded.insert(encoded.begin(),first);
        for(int i=1;i<=n;i++)
        {
            encoded[i]=encoded[i]^encoded[i-1];
        }
        return encoded;
    }