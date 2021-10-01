#include<bits/stdc++.h>
using namespace std;

int dp[100][100];
int solve(int e,int f)
{
    if(f==0||e==1||f==1)
        return f;

    int mn = INT_MAX;
    if(dp[e][f]!=-1)
        return dp[e][f];
    for(int k=1;k<=f;k++)
    {
        int temp = 1+max(solve(e-1,k-1),solve(e,f-k));

        mn = min(temp,mn);
    }
    return dp[e][f]= mn;
}
main()
{

    memset(dp,-1,sizeof(dp));
    int e = 3;
    int f = 5;
    cout<<solve(e,f);
}