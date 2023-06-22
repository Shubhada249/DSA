//https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/

//TC:O(n)       //SC:O(1)
int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i=0,j=0,n=arr.size(),sum=0,ans=0;
        while(j<n)
        {
            sum+=arr[j];
            if(j-i+1<k)
                j++;
            else if(j-i+1==k)       
            {
                if(sum*1.0/k >=threshold)
                    ans++;
                sum-=arr[i];
                i++;
                j++;
            }
        }
        return ans;
    }