//https://leetcode.com/problems/set-matrix-zeroes/

//TC:O(m*n) //SC:O(m+n)
void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> r,c;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    r.insert(i);
                    c.insert(j);
                }
            }
        }
        for(auto it:r)
        {
            for(int j=0;j<n;j++)
            {
                matrix[it][j]=0;
            }
        }
        for(auto it:c)
        {
            for(int j=0;j<m;j++)
            {
                matrix[j][it]=0;
            }
        }
    }

//TC:O(m*n) //SC:O(1)
//Edge Case: matrix[0][0] //if u want to only mark row 0 as 0,so u will matrix[0][0]=0.This will also mark col 0 as 0 later which is wrong. For this u have created separate variable c,r.
void setZeroes(vector<vector<int>>& matrix) {
        int r=0,c=0;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    if(i==0)
                    {
                        r=1;
                    }
                    if(j==0)
                    {
                        c=1;
                    }
                    else if(i!=0 && j!=0)
                    {
                        matrix[i][0]=0;
                        matrix[0][j]=0;
                    }
                }
            }
        }
        for(int i=1;i<m;i++)
        {
            if(matrix[i][0]==0)
            {
                for(int j=1;j<n;j++)
                {
                    matrix[i][j]=0;
                }
            }
        }
        for(int j=1;j<n;j++)
        {
            if(matrix[0][j]==0)
            {
                for(int i=1;i<m;i++)
                {
                    matrix[i][j]=0;
                }
            }
        }
        if(r==1)
        {
            for(int j=0;j<n;j++)
                matrix[0][j]=0;
        }
        if(c==1)
        {
            for(int i=0;i<m;i++)
                matrix[i][0]=0;
        }
        
    }