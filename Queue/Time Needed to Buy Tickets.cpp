//https://leetcode.com/problems/time-needed-to-buy-tickets/

//TC:O(count)   //SC:O(1)
int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n=tickets.size(),count=0;
        for(int i=0;;i=(i+1)%n)
        {            
            if(tickets[i]!=0)
            {
                tickets[i]--;
                count++;
            }
            if(tickets[k]==0)
                return count;
        }
        return count;
    }

//TC:O(n)   //SC:O(1)
int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n=tickets.size(),count=0;
        for(int i=0;i<n;i++)
        {            
            if(i<=k)
            {
                count+=min(tickets[i],tickets[k]);
            }
            else
            {
                count+=min(tickets[i],tickets[k]-1);
            }
        }
        return count;
    }