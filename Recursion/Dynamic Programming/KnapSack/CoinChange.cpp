#include<bits/stdc++.h>
using namespace std;


int dp[5][5] ={0};
int coinChange(int a[],int k,int n)
{
    if(k==0)
        return 1;
    if(k<0)
        return 0;
    if(k>0 && n<0)
        return 0;

    return coinChange(a,k-a[n],n)+coinChange(a,k,n-1);
}
main()
{
    int n =3;
    int a[3] ={1,2,3};
    int k = 5;
    cout<<coinChange(a,k,n-1);
}