//https://leetcode.com/problems/game-of-life/

/*Note:Whenever we are asked to do something in-place, we are mostly given the luxury of modifying our input data structure itself. For example see this question, even though a cell can only be in one of two states (dead or alive), we are given an integer matrix, where a bool matrix would obviously have been sufficient.
We can take benefit of this.*/

//TC:O(mn)  //SC:O(mn) 
int LiveNeighbours(int r,int c,vector<vector<int>>& board,int m,int n)
{
    int count=0;
    for(int row=r-1;row<=r+1;row++)
    {
        for(int col=c-1;col<=c+1;col++)
        {
            if(row>=0 && row<m && col>=0 && col<n)
            {
                if(row==r && col==c)
                    continue;
                if(board[row][col]==1)
                    count++;
            }
        }
    }
    return count;
}
void gameOfLife(vector<vector<int>>& board) {
    int m=board.size(),n=board[0].size();
    vector<vector<int>> dp(m,vector<int>(n,0));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            int num=LiveNeighbours(i,j,board,m,n);
            if(board[i][j]==1)
            {
                if(num<2)
                    dp[i][j]=0;
                else if(num==2 || num==3)
                    dp[i][j]=1;
                else if(num>3)
                    dp[i][j]=0;
            }
            else
            {
                if(num==3)
                    dp[i][j]=1;
            }
        }
    }
    board=dp;
}












//TC:O(mn)  //SC:O(1)    
int After(int num)
{
    if(num==10 || num==30)
        return 1;
    else 
        return 0;
}
int Before(int num)
{
    if(num==1 || num==10 || num==20)
        return 1;
    else
        return 0;
}
int LiveNeighbours(int r,int c,vector<vector<int>>& board,int m,int n)
{
    int count=0;
    for(int row=r-1;row<=r+1;row++)
    {
        for(int col=c-1;col<=c+1;col++)
        {
            if(row>=0 && row<m && col>=0 && col<n)
            {
                if(row==r && col==c)
                    continue;
                int st=Before(board[row][col]);
                if(st==1)
                    count++;
            }
        }
    }
    return count;
}
void gameOfLife(vector<vector<int>>& board) {
    int m=board.size(),n=board[0].size();
    //vector<vector<int>> dp(m,vector<int>(n,0));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            int num=LiveNeighbours(i,j,board,m,n);
            if(board[i][j]==1)
            {
                if(num<2)
                    board[i][j]=20;
                else if(num==2 || num==3)
                    board[i][j]=10;
                else if(num>3)
                    board[i][j]=20;
            }
            else
            {
                if(num==3)
                    board[i][j]=30;
                else
                    board[i][j]=40;
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            int st=After(board[i][j]);
            board[i][j]=st;
        }
    }
}