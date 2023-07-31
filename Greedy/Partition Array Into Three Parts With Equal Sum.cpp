//https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/

//TC:O(n)   //SC:O(1)
bool canThreePartsEqualSum(vector<int>& arr) {
        int n=arr.size();
        long long sum=accumulate(arr.begin(),arr.end(),0);
        if(sum%3!=0)
            return false;
        long long part=sum/3;
        sum=0;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
           sum+=arr[i];
            if(sum==part)
            {
                sum=0;
                cnt++;
            }
        }
        return cnt>=3;
        
    }