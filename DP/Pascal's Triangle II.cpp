//https://leetcode.com/problems/pascals-triangle-ii/
vector<int> getRow(int rowIndex) {
    vector<int> cur(rowIndex+1,0);
    for(int i=0;i<=rowIndex;i++)
    {
        for(int j=i;j>=0;j--)
        {
            if(i==0 || j==0 || i==j)
                cur[j]=1;
            else
                cur[j]=cur[j]+cur[j-1]; //Imp
        }
    }
    return cur;
}