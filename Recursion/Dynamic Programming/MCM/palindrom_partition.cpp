#include<bits/stdc++.h>
using namespace std;


int dp[100][100];
bool isPalindrom(string s,int i,int j)
{
    while(i<=j)
    {
        if(s[i]!=s[j])
            return false;

        i++;
        j--;
    }
    return true;
}
int solve(string s,int i,int j)
{
    if(i>j)
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];
    if(isPalindrom(s,i,j)==true)
        return 0;
    
    int mn = INT16_MAX;
    for(int k=i;k<=j-1;k++)
    {   

        // int tempAns = solve(s,i,k)+solve(s,k+1,j)+1;
        // int tempAns = left +       right +        1;

        int left ;
        int right;

        //calculating or checking in dp for left
        if(dp[i][k]!=-1)
            left = dp[i][k];
        else{
            left = solve(s,i,k);
            dp[i][k] = left;
        }


        //calculating or checking in dp for right
        if(dp[k+1][j]!=-1)
            right = dp[k+1][j];
        else{
            right = solve(s,k+1,j);
            dp[k+1][j] = right;
        }


        //Temp ans
        int tempAns = left + right +1;

        mn = min(mn,tempAns);

    }
    
    return dp[i][j] = mn;
}
main()
{
    string s = "ABC";
    int n = s.length();

    memset(dp,-1,sizeof(dp));
    cout<<solve(s,0,n-1);
}