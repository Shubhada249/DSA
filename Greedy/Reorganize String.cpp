//https://leetcode.com/problems/reorganize-string/

//TC:O(n log k)     SC:O(k) //k is no. of unique chars in string
string reorganizeString(string s) {
        int n=s.size();
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> mp;
        for(auto c:s)
        {
            mp[c]++;
        }
        
        
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }
        if(pq.top().first > ceil(n/2.0))
            return "";
        string ans="";
        while(pq.size()>=2)
        {
            pair<int,char> p1,p2;

            p1=pq.top();
            ans.push_back(p1.second);           //
            (p1.first)--;
            pq.pop();
            
            p2=pq.top();
            ans.push_back(p2.second);           //
            (p2.first)--;
            pq.pop();
            
            if(p1.first!=0)
                pq.push(p1);
            if(p2.first!=0)
                pq.push(p2);
                
        }
        if(pq.size()==1)
        {
            ans.push_back(pq.top().second);
        }
        
        return ans;
    }

    //TC:O(n)   //SC:O(k)
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        int n=s.size(),i=0;
        char cr;
        int maxfreq=0;
        for(auto c:s)
        {
            mp[c]++;
            if(mp[c]>maxfreq)
            {
                maxfreq=mp[c];
                cr=c;
            }
        }
        if(maxfreq>ceil(n/2.0))
            return "";
        int last;
        if(n%2==0)
            last=n-2;
        else
            last=n-1;
        string ans=s;
        bool ch=false;
        if(n%2!=0 && maxfreq==(n/2)+1)
        {
            while(mp[cr]--)
            {
                ans[i]=cr;
                i=i+2;
            }
            mp.erase(cr);
        }
            
        for(auto it:mp)
        {
            int v=it.second;
            while(v--)
            {
                if(i>last && ch==false)
                {
                    i=1;
                    ch=true;
                }
                ans[i]=it.first;
                i=i+2;
            }
        }
        return ans;
    }