//https://practice.geeksforgeeks.org/problems/merge-sort/1

//TC: BC=AC=WC=O(n log n) //SC:O(n)
void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int p=l,q=m+1;
         vector<int> temp;
         while(p<=m && q<=r)
         {
             if(arr[p]<=arr[q])
             {
                 temp.push_back(arr[p]);
                 p++;
             }
             else
             {
                 temp.push_back(arr[q]);
                 q++;
             }
         }
         while(p<=m)
         {
              temp.push_back(arr[p]);
              p++;
         }
         while(q<=r)
         {
             temp.push_back(arr[q]);
             q++;
         }
         for(int k=0;k<temp.size();k++)
         {
             arr[l]=temp[k];
             l++;
         }
         
    }
   
    void mergeSort(int arr[], int l, int r)
    {
        if(l==r)
            return;
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }