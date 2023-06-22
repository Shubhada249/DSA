//https://leetcode.com/problems/kth-largest-element-in-an-array/

//TC:O(n log n)     //SC:O(1)
int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end(),[&](int a,int b){return a>b;});
    return nums[k-1];
}
//TC:O(n log k)     //SC:O(k)
int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(i<k)
                pq.push(nums[i]);
            else if(nums[i]>pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }

//TC:O(n)   //SC:O(1)
int partition(int low,int high,vector<int>& nums)
{
    int pivot=nums[low],i=low+1,j=high;
    while(i<=j)
    {
        if(nums[i]> pivot && nums[j]<=pivot)
        {
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
        else if(nums[i]<=pivot)
            i++;
        else
            j--;
    }
    swap(nums[low],nums[j]);
    return j;
}
int findKthLargest(vector<int>& nums, int k) {        
    int n=nums.size();
    k=n-k;
    int low=0,high=n-1;
    while(true)
    {
        int j=partition(low,high,nums);
        if(j==k)
            return nums[k];
        else if(j<k)
        {
            low=j+1;
        }
        else
        {
            high=j-1;
        }
    }
    return nums[0];
}