//https://leetcode.com/problems/find-the-original-array-of-prefix-xor/

//TC:O(n)   //SC:O(1)
vector<int> findArray(vector<int>& pref) {
        int n=pref.size();
        vector<int> ans(n,0);
        ans[0]=pref[0];
        for(int i=1;i<n;i++)
        {
            ans[i]=pref[i]^pref[i-1];
        }
        return ans;
    }

//TC:O(n)   //SC:O(1)   //in place solution
vector<int> findArray(vector<int>& pref) {
        int n=pref.size();
        for(int i=n-1;i>0;i--)
        {
            pref[i]=pref[i]^pref[i-1];
        }
        return pref;
    }