//https://practice.geeksforgeeks.org/problems/second-largest3735/1

//TC:O(n)//SC:O(1)
int print2largest(int arr[], int n) {
	    // code here
	    int l=INT_MIN;
	    int sl=INT_MIN;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]>l)
	        {
	            sl=l;
	            l=arr[i];
	        }
	        else if(l!=arr[i] && arr[i]>sl)
	        {
	            sl=arr[i];
	        }
	    }
	    if(sl==INT_MIN)
	        return -1;
	    return sl;
	}