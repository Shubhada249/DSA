//https://leetcode.com/problems/sort-the-students-by-their-kth-score/

//TC:O(n)//SC:O(n)
vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        vector<vector<int>> ans;
        set<pair<int,int>> st;
        for(int i=0;i<score.size();i++) //TC:O(log n)
        {
            st.insert({score[i][k],i});
        }
        for(auto it:st) //TC:O(n)
        {
            int j=(it).second;
            ans.insert(ans.begin(),score[j]);
        }
        return ans;
    }

//TC:O(n log n)//SC:O(1)
vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(),score.end(),[&](vector<int> &a,vector<int> &b){return a[k]>b[k];});
        return score;
    }