//https://practice.geeksforgeeks.org/problems/largest-element-in-array4009/0

//TC:O(n)//SC:O(1)
int largest(vector<int> &arr, int n)
    {
        return *max_element(arr.begin(),arr.end());
    }