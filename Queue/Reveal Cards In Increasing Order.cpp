//https://leetcode.com/problems/reveal-cards-in-increasing-order/
//TC:O(n log n)     //SC:O(1)
vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        sort(deck.begin(),deck.end());
        vector<int> ans(n,-1);
        int count=0,i=0;
        while(count!=n)
        {
            while(ans[i]!=-1)
                i=(i+1)%n;
            ans[i]=deck[count];
            i=(i+1)%n;
            count++;
            while(count!=n && ans[i]!=-1)
                i=(i+1)%n;
            i=(i+1)%n;
        }
        return ans;
    }

//TC:O(2n)  //SC:O(n)
 vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        sort(deck.begin(),deck.end());
        vector<int> ans(n,-1);
        int count=0;
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            q.push(i);
        }
        while(!q.empty())
        {
            ans[q.front()]=deck[count++];
            q.pop();
            if(!q.empty())
            {
                q.push(q.front());
                q.pop();
            }
        }
        return ans;
    }