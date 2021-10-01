#include<bits/stdc++.h>
using namespace std;

 int dp[100][100];
// int LCS(string s,string t,int n,int m)
// {
//     if(n==0 || m==0)
//         return dp[n][m] =0;
//     if(dp[n][m]!=-1)
//         return dp[n][m];
//     if(s[n-1]==t[m-1])
//         return dp[n][m]=1+LCS(s,t,n-1,m-1);
//     else
//         return dp[n][m]=max(LCS(s,t,n-1,m),LCS(s,t,n,m-1));
// }



int LCSTopDOwn(string s,string t,int n,int m)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0||j==0)
                dp[i][j]=0;
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==t[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = 0;
        }
    }

    int ans = 0;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            ans = max(ans,dp[i][j]);
        }
    }

    return ans;
    
}
main()
{
    string s = "abcde";
    string t = "ababcde";
    memset(dp,-1,sizeof(dp));
    cout<<LCSTopDOwn(s,t,s.length(),t.length());

/*
    for(int i=0;i<=s.size();i++)
    {
        for(int j=0;j<=t.size();j++)
        {
            cout<<dp[i][j]<<",";
        }
        cout<<endl;
    }

*/
}