//https://leetcode.com/problems/find-k-closest-elements/

//TC:O(log n + 2k)   //SC:O(1)
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size(),low=0,high=n-1,cnt=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid]==x)
            {
                cnt++;
                low=mid+1;
                high=mid-1;
                break;
            }
            else if(arr[mid]<x)
                low=mid+1;
            else
                high=mid-1;
        }

        while(cnt!=k && high>=0 && low<n)
        {
            int d1=x-arr[high];
            int d2=arr[low]-x;
            if(d1<=d2)
                high--;
            else
                low++; 
            cnt++;
        }
        while(cnt!=k && high<0)
        {
            low++;
            cnt++;
        }
        while(cnt!=k && low==n)
        {
            high--;
            cnt++;
        }
        vector<int> vec(arr.begin()+high+1,arr.begin()+low);  
        return vec;
    }

//TC:O(log (n-k) + k)   //SC:O(1)       //k for copying k elements
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size(),low=0,high=n-k;
        while(low<high)
        {
            int mid=low+(high-low)/2;
            if(x-arr[mid]==arr[mid+k]-x)
            {
                if(arr[mid]!=arr[mid+k])
                    high=mid;
                else if(x>arr[mid])
                    low=mid+1;
                else
                    high=mid;
            }
            
            else if(x-arr[mid] < arr[mid+k]-x)
                high=mid;
            
            else
                low=mid+1;            
        }
    
        vector<int> vec(arr.begin()+low,arr.begin()+low+k);  
        return vec;
    }