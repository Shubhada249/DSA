//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

//TC:O(n)   //SC:O(1)
vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int i=0,j=n-1;
        while(i<j)
        {
            int sum=numbers[i]+numbers[j];
            if(sum>target)
                j--;
            else if(sum<target)
                i++;
            else
                return {i+1,j+1};
        }
        return {0,0};
    }