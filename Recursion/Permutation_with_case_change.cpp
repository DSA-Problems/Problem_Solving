#include<bits/stdc++.h>
using namespace std;

void solve(string input,string  ans)
{
    if(input.size()==0)
    {
        cout<<ans<<endl;
        return;
    }
    string op1 = ans;
    string op2 = ans;

    op1.push_back(input[0]);
    op2.push_back(toupper(input[0]));
    solve(input.substr(1),op1);
    solve(input.substr(1),op2);

    return ;
}

main()
{
    solve("ab","");
}