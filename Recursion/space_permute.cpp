#include<bits/stdc++.h>
using namespace std;


void solve(string input,string ans)
{

    if(input.size()==0)
    {
        cout<<ans<<endl;
        return;
    }

    solve(input.substr(1),ans+"-"+input[0]);
    solve(input.substr(1),ans+input[0]);

    return ;

}


main()
{

    string s = "ABC";

    string output = "";

    output = output+s[0];

    s = s.substr(1);

    solve(s,output);
}