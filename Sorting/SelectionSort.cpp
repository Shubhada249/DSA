//https://practice.geeksforgeeks.org/problems/selection-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=selection-sort

//TC: BC=AC=WC=O(n^2)//SC:O(1)
void selectionSort(int arr[], int n)
    {
       //code here
       for(int i=0;i<n-1;i++)
       {
            int ind=i;
            for(int j=i+1;j<n;j++)
            {
                if(arr[ind]>arr[j])
                    ind=j;
            }
            if(ind!=i)
                swap(arr[ind],arr[i]);
       }
    }