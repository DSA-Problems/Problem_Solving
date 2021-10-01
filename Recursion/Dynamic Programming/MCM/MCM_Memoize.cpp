#include<bits/stdc++.h>
using namespace std;


int dp[100][100];

int solve(int a[],int i,int j)
{
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(i>=j)
        return 0;
    
    int mn = INT16_MAX;

    for(int k=i;k<=j-1;k++)
    {   
        //temp ans
        int tempAns = solve(a,i,k)+solve(a,k+1,j)+a[i-1]*a[k]*a[j];

        //calculating final ans
        mn = min(mn,tempAns);
    }
    return dp[i][j]=mn;
}
main()
{
    int arr[4]={10,30,5,60};
    int n=4;
    memset(dp,-1,sizeof(dp));
    cout<<solve(arr,1,n-1);

}