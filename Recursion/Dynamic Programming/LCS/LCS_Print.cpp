#include<bits/stdc++.h>
using namespace std;


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


/* Method 1 
 string dp[100][100];
string LCSTopDOwn(string s,string t,int n,int m)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0||j==0)
            dp[i][j]="";
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==t[j-1])
                dp[i][j] = dp[i-1][j-1]+s[i-1];
            else
            {
                if(dp[i-1][j].length()>dp[i][j-1].length())
                        dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i][j-1];
            }
                
        }
    }

    return dp[n][m];
    
}
*/


// Method 2

int dp[100][100];
string LCSTopDOwn(string  a, string b,int n,int m) {
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0)
                dp[i][j]=0;
        }
    }

    //create DP table
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }


    // calculate the ans
    int i=n;
    int j=m;
   string v;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            v.push_back(a[i-1]);
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1])
                i--;
            else 
                j--;
        }
    }
    reverse(v.begin(),v.end());
    return v;
}
main()
{
    string s = "abcdef";
    string t = "abaf";
    cout<<LCSTopDOwn(s,t,s.length(),t.length());
}