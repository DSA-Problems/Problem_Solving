#include<bits/stdc++.h>
using namespace std;

void solve(vector<string>& v,string op,int n,int one,int zero)
{
    if(n==0)
    {
        
            //  cout<<"he";
            v.push_back(op);
            return;
    }
   
    solve(v,op+"1",n-1,one+1,zero);

    if(one>zero)
    solve(v,op+"0",n-1,one,zero+1);
    return;;
}
main()
{
    int n= 3;
    vector<string> v;
    solve(v,"",n,0,0);

    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;;
    }
}