//https://leetcode.com/problems/pascals-triangle/

//TC:O(n^2)     //O(2n)
vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++)
        {
            if(i==1)
                ans.push_back({1});
            else
            {
                vector<int> prev(ans[i-2].begin(),ans[i-2].end());
                vector<int> cur;
                for(int j=0;j<prev.size()-1;j++)
                {
                    int ele=prev[j]+prev[j+1];
                    cur.push_back(ele);
                }
                cur.push_back(1);
                cur.insert(cur.begin(),1);
                ans.push_back(cur);
            }
        }
        return ans;
    }

//TC:O(n^2)     //SC:O(1)
vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0;i<numRows;i++)
        {
            ans.push_back(vector<int>(i+1,1));
            for(int j=1;j<i;j++)
            {
                ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
            }
        }
        return ans;
    }