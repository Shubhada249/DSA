//https://practice.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/0

//TC:O(2N)//SC:O(N)
void frequencyCount(vector<int>& arr,int N, int P)
    { 
        // code here
        map<int,int> mp;
        for(int i=0;i<N;i++)
        {
            if(arr[i]<=N)
            {
                mp[arr[i]]++;
            }
        }
        for(int i=0;i<N;i++)
        {
            arr[i]=mp[i+1];
        }
    }



//TC:O(3N)//SC:O(1)
void frequencyCount(vector<int>& arr,int N, int P)
    { 
        // code here
        for(int i=0;i<N;i++)
        {
            if(arr[i]>N)
                arr[i]=0;
        }
        int i=0;
        while(i<N)
        {
            while(arr[i]>0)
            {
                int ind=arr[i]-1;
                if(arr[ind]>0)
                {
                    arr[i]=arr[ind];
                    arr[ind]=-1;
                }
                else
                {
                    arr[ind]--;
                    arr[i]=0;
                }
            }
            i++;
        }
        for(int i=0;i<N;i++)
        {
            arr[i]=0-arr[i];
        }
    }


//TC:O(3N)//SC:O(1)
void frequencyCount(vector<int>& arr,int N, int P)
    { 
        // code here
        for(int i=0;i<N;i++)
        {
            arr[i]--;
        }
        
        for(int i=0;i<N;i++)
        {
            if(arr[i]%P<N)
            {
                int ind=arr[i]%P;
                arr[ind]+=P;
            }
        }
        for(int i=0;i<N;i++)
        {
            arr[i]=arr[i]/P;
        }
    }



