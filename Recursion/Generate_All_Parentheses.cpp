#include<bits/stdc++.h>
using namespace std;


void solve(vector<string>& v,string op,int n,int m)
{
    if(n==0&&m==0)
    {
        v.push_back(op);
        return;
    }

    if(n!=0)
    {
        solve(v,op+"(",n-1,m);
    }

    if(n<m)
    {
        solve(v,op+")",n,m-1);
    }
    return;
}
main(){

    vector<string> v;

    int n=3;
    int m =3;
    string op = "";

    solve(v,"",n,m);

    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}