#include<bits/stdc++.h>
using namespace std;
vector<string> v;
//Function to return the lexicographically sorted power-set of the string.
void solve(string s,string ans)
{
    if(s.size()==0)
    {
        if(ans!=" ")
      v.push_back(ans);
     return;
    } 
    string op1 = ans;
    string op2  = ans;
    
    op2.push_back(s[0]);
    
    s.erase(s.begin()+0);
    
    solve(s,op1);
    solve(s,op2);
    return;
}

main()
{
    solve("abc","");


    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}