//https://leetcode.com/problems/sort-colors/
//https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/

//O(n)  //O(1)
void sortColors(vector<int>& nums) {
    int n=nums.size(),i=0,zero=0,second=n-1;
    while(i<=second)
    {
        if(nums[i]==1)
        {
            i++;
            continue;
        }
        else if(nums[i]==0)
        {
            swap(nums[zero],nums[i]);
            zero++;
            i++;
            continue;
        }
        else
        {
            swap(nums[second],nums[i]);
            second--;
            continue;
        }
    }
}