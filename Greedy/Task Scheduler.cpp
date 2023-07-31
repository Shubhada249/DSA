//https://leetcode.com/problems/task-scheduler/

//TC:O(n)   //SC:O(26)
int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        int sz=tasks.size();
        int max_freq=0,max_freq_chars=0;
        for(int i=0;i<sz;i++)
        {
            mp[tasks[i]]++;
            max_freq=max(max_freq,mp[tasks[i]]);
        }
        for(auto it:mp)
        {
            if(it.second==max_freq)
                max_freq_chars++;
        }
        int parts=max_freq-1;
        int min_partLength=n-(max_freq_chars-1);
        int emptyslots=parts*min_partLength;
        int availablechars=sz-(max_freq_chars*max_freq);
        if(emptyslots<=availablechars)
            return sz;
        int idles=emptyslots-availablechars;
        return sz+idles;//(n+1)*(max_freq-1)+max_freq_chars;
    }