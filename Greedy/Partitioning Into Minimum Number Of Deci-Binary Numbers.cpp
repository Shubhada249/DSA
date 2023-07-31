//https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/

//TC:O(n)   //SC:O(1)
int minPartitions(string n) {
        int ans=n[0]-'0';
        for(int i=1;i<n.size();i++)
        {
            ans=max(ans,n[i]-'0');
        }
        return ans;
    }