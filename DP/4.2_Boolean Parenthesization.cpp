//https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

int fun(int i,int j,string &S,int isTrue,vector<vector<vector<int>>> &dp)
    {
        if(dp[i][j][isTrue]!=-1)
            return dp[i][j][isTrue]%1003;
        if(i==j)
        {
            if(S[i]=='T')
            {
                if(isTrue)
                    return dp[i][j][isTrue]=1;
                else
                    return dp[i][j][isTrue]=0;
            }
            else
            {
                if(isTrue)
                    return dp[i][j][isTrue]=0;
                else
                    return dp[i][j][isTrue]=1;
            }
        }
        int ans=0;
        for(int k=i+1;k<j;k=k+2)
        {
            int T1,T2,F1,F2;
            T1=fun(i,k-1,S,1,dp);
            F1=fun(i,k-1,S,0,dp);
            T2=fun(k+1,j,S,1,dp);
            F2=fun(k+1,j,S,0,dp);
            int T,F;
            if(S[k]=='|')
            {
                if(isTrue)
                    T=T1*T2+T1*F2+F1*T2;
                else
                    F=F1*F2;
            }
            else if(S[k]=='&')
            {
                if(isTrue)
                    T=T1*T2;
                else
                    F=T1*F2+F1*T2+F1*F2;
            }
            else
            {
                if(isTrue)
                    T=T1*F2+F1*T2;
                else
                    F=T1*T2+F1*F2;
            }
            if(isTrue)
                ans+=T;
            else
                ans+=F;
        }
        return dp[i][j][isTrue]=ans%1003;
    }
    int countWays(int N, string S){
        // code here
        vector<vector<vector<int>>> dp(N,vector<vector<int>>(N,vector<int>(2,-1)));
        //return fun(0,N-1,S,1,dp);
        for(int i=N-1;i>=0;i--)
        {
            for(int j=i;j<N;j++)
            {
                for(int isTrue=0;isTrue<2;isTrue++)
                {
                    if(i==j)
                    {
                        if(S[i]=='T')
                        {
                            if(isTrue)
                                dp[i][j][isTrue]=1;
                            else
                                dp[i][j][isTrue]=0;
                        }
                        else
                        {
                            if(isTrue)
                                dp[i][j][isTrue]=0;
                            else
                                dp[i][j][isTrue]=1;
                        }
                    }
                    else
                    {
                        int ans=0;
                        for(int k=i+1;k<j;k=k+2)
                        {
                            int T1,T2,F1,F2;
                            T1=dp[i][k-1][1];
                            F1=dp[i][k-1][0];
                            T2=dp[k+1][j][1];
                            F2=dp[k+1][j][0];
                            int T,F;
                            if(S[k]=='|')
                            {
                                if(isTrue)
                                    T=T1*T2+T1*F2+F1*T2;
                                else
                                    F=F1*F2;
                            }
                            else if(S[k]=='&')
                            {
                                if(isTrue)
                                    T=T1*T2;
                                else
                                    F=T1*F2+F1*T2+F1*F2;
                            }
                            else
                            {
                                if(isTrue)
                                    T=T1*F2+F1*T2;
                                else
                                    F=T1*T2+F1*F2;
                            }
                            if(isTrue)
                                ans+=T;
                            else
                                ans+=F;
                        }
                        dp[i][j][isTrue]=ans%1003;
                    }
                }
            }
        }
        return dp[0][N-1][1];
    }