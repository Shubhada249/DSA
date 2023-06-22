//https://leetcode.com/problems/valid-sudoku/

//TC:O(243)     //SC:O(9)
bool isValidSudoku(vector<vector<char>>& board) {
    for(int row=0;row<9;row++)
    {
        map<char,int> mp;
        for(int j=0;j<9;j++)
        {
            if(board[row][j]!='.')
            {
                mp[board[row][j]]++;
                if(mp[board[row][j]]>1)
                    return false;     
            }
        }
    }
    
    for(int col=0;col<9;col++)
    {
        map<char,int> mp;
        for(int i=0;i<9;i++)
        {
            if(board[i][col]!='.')
            {
                mp[board[i][col]]++;
                if(mp[board[i][col]]>1)
                    return false;
            }
        }
    }
    for(int i=0;i<9;i=i+3)
    {
        for(int j=0;j<9;j=j+3)
        {
            map<char,int> mp;
            for(int k=i;k<i+3;k++)
            {
                for(int l=j;l<j+3;l++)
                {
                    if(board[k][l]!='.')
                    {
                        mp[board[k][l]]++;
                        if(mp[board[k][l]]>1)
                            return false;
                    }
                }
            }
        }
    }
    
    return true;
}


//TC:O(81)      //SC:O(81)
int findBoxNo(int r,int c)
{
    if(r>=0 && r<=2)
    {
        if(c>=0 && c<=2)
            return 0;
        else if(c>=3 && c<=5)
            return 1;
        else
            return 2;
    }
    else if(r>=3 && r<=5)
    {
        if(c>=0 && c<=2)
            return 3;
        else if(c>=3 && c<=5)
            return 4;
        else
            return 5;
    }
    else
    {
        if(c>=0 && c<=2)
            return 6;
        else if(c>=3 && c<=5)
            return 7;
        else
            return 8;
    }
}
bool isValidSudoku(vector<vector<char>>& board) {
    map<string,int> mp;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(board[i][j]!='.')
            {
                int k=findBoxNo(i,j);
                string st1="row+"+to_string(i)+"+"+board[i][j];
                string st2="col+"+to_string(j)+"+"+board[i][j];
                string st3="box+"+to_string(k)+"+"+board[i][j];
                mp[st1]++;
                if(mp[st1]>1)
                    return false;
                mp[st2]++;
                if(mp[st2]>1)
                    return false;
                mp[st3]++;
                if(mp[st3]>1)
                    return false;
            }
        }
    }
    return true;
}