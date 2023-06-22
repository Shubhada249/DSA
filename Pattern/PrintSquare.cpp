//https://practice.geeksforgeeks.org/problems/square-pattern-1662666141/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=pattern_22
//NY
//https://drive.google.com/file/d/1xLxtJnMj7iovnidni2hgvIr70LxuBGW3/view
void printSquare(int n) 
{
    // code here
    for(int i=0;i<=2*(n-1);i++)
    {
        for(int j=0;j<=2*(n-1);j++)
        {
            if(i+j<=2*n-2)
                cout<<n-min(i,j)<<" ";
            else
                cout<<max(i,j)+2-n<<" ";
        }
        cout<<"\n";
    }
}

//https://youtu.be/tNm_NNSB3_w?t=4541
void printSquare(int n) 
{
    // code here
    for(int i=0;i<=2*(n-1);i++)
    {
        for(int j=0;j<=2*(n-1);j++)
        {
            int left=j;
            int right=2*n-2-j;
            int top=i;
            int bottom=2*n-2-i;
            int mini=min(min(left,right),min(top,bottom));
            cout<<n-mini<<" ";
        }
        cout<<"\n";
    }
}