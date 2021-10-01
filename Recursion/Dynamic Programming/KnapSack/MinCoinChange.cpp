#include<bits/stdc++.h>
using namespace std;

int dp[100][100];
int MinCoin(int coin[],int sum,int n)
{

    //Intialize the first row
    for(int i=1;i<=sum;i++)
    {
       dp[0][i]=INT_MAX-1;
    }

    //intialize the first column
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=0;
    }

    //Intialize the second row
    for(int i=1;i<=sum;i++)
    {
        if(i%coin[0]==0)
            dp[1][i]=i/coin[0];
        else{
           dp[1][i]=INT_MAX-1;   
        }
    }


    // DP interation and filling the rest table  
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {

            if(coin[i-1]<=j)
             dp[i][j]= min(dp[i][j-coin[i-1]]+1,dp[i-1][j]);
            else
             dp[i][j]=dp[i-1][j];
        }
        cout<<endl;
    }
    return dp[n][sum];

}
main()
{
    int n =5;
    int coin[n] ={1,2,3,5,8};
    int sum = 8;

    cout<<MinCoin(coin,sum,n);

    cout<<"\n";
     for(int i=0;i<=n;i++)
     {
         for(int j=0;j<=sum;j++)
         { 
             cout<<dp[i][j]<<",";
         }
         cout<<endl;
     }
}