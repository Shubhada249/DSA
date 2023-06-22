//https://practice.geeksforgeeks.org/problems/bubble-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bubble-sort
//TC: BC=AC=WC=O(n^2)//SC:O(1)
void bubbleSort(int arr[], int n)
    {
        // Your code here  
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-1-i;j++)
            {
                if(arr[j]>arr[j+1])
                    swap(arr[j],arr[j+1]);
            }
        }
    }