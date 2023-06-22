//https://leetcode.com/problems/sort-colors/

//O(2n)     //O(1)
void sortColors(vector<int>& nums) {
    int n=nums.size();
    int i=0,j=0;
    while(j<n)
    {
        if(nums[j]!=2)
        {
            swap(nums[j],nums[i]);
            i++;
            j++;
        }
        else 
            j++;
    }
    n=i;
    i=0;
    j=0;
    while(j<n)
    {
        if(nums[j]!=1)
        {
            swap(nums[j],nums[i]);
            i++;
            j++;
        }
        else 
            j++;
    }
}


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