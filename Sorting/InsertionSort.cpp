//https://practice.geeksforgeeks.org/problems/insertion-sort/0?category[]=Algorithms&page=1&query=category[]Algorithmspage1&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=insertion-sort

//TC: AC=WC=O(n^2) BC:O(n)//SC:O(1)
void insertionSort(int arr[], int n)
    {
        //code here
        for(int i=1;i<n;i++)
        {
            int ele=arr[i];
            for(int j=i-1;j>=-1;j--)
            {
                if(j==-1)
                {
                    arr[j+1]=ele;
                    break;
                }
                else if(arr[j]>ele)
                    arr[j+1]=arr[j];
                else
                {
                    arr[j+1]=ele;
                    break;
                }
            }
        }
    }