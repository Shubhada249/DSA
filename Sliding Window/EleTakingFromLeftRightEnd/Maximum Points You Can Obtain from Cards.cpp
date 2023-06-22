//https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

//TC:O(2n)  //SC:O(n)
int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        vector<int> rt(n,0);
        rt[n-1]=cardPoints[n-1];
        for(int i=n-2;i>=0;i--)
        {
            rt[i]=rt[i+1]+cardPoints[i];
        }
        int lt=0,ans=0;
        for(int i=0;i<k;i++)
        {
            lt+=cardPoints[i];
            if(n-k+i+1==n)
                ans=max(ans,lt);
            else
                ans=max(ans,lt+rt[n-k+i+1]);
        }
        return max(ans,rt[n-k]);
    }

//TC:O(n)   //SC:O(1)
    int maxScore(vector<int>& cardPoints, int k) {
        int i=0,j=0,n=cardPoints.size(),total=accumulate(cardPoints.begin(),cardPoints.end(),0),mini=total,ws=n-k;
        if(ws==0)
            return total;
        int sum=0;
        while(j<n)
        {
            sum=sum+cardPoints[j];
            if(j-i+1<ws)
                j++;
            else if(j-i+1==ws)
            {
                mini=min(mini,sum);
                sum-=cardPoints[i];
                i++;
                j++;
            }
        }
        return total-mini;
    }