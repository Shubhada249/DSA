//https://leetcode.com/problems/take-gifts-from-the-richest-pile/

//TC:O(k*n=n^2)  k=n in worst case    //SC:O(1)
int findMax(vector<int>& gifts)
    {
        int ind=0;
        for(int i=1;i<gifts.size();i++)
        {
            if(gifts[i]>gifts[ind])
                ind=i;
        }
        return ind;
    }
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans=0;
        int n=gifts.size();
        
        for(int i=0;i<k;i++)
        {
            int ind=findMax(gifts);
            gifts[ind]=sqrt(gifts[ind]);
        }
         for(int i=0;i<n;i++)
        {
            ans+=(long long)gifts[i];
        }
        return ans;
    }

//TC:O((2k+2n) log n=4n log n) k=n in worst case    //SC:O(n)
long long pickGifts(vector<int>& gifts, int k) {
        long long ans=0;
        int n=gifts.size();
        priority_queue<int> pq;
        for(int i=0;i<n;i++)
        {
            pq.push(gifts[i]);
        }
        for(int i=0;i<k;i++)
        {
            int maxi=pq.top();
            pq.pop();
            pq.push(sqrt(maxi));
        }
        while(!pq.empty())
        {
            ans+=(long long)pq.top();
            pq.pop();
        }
        return ans;
    }