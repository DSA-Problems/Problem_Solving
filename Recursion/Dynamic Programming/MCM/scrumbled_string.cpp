#include<bits/stdc++.h>
using namespace std;


unordered_map<string,int> mp;
bool solve(string a,string b)
{
    if(a.compare(b)==0)
        return true;
    if(a.length()<=1)
        return false;

    int n = a.length();
    int flag = false;  // a & b is not scrambled
    
    string temp = a+"_"+b;

    if(mp.find(temp)!=mp.end())
        return mp[temp];
    for(int i=1;i<n;i++)
    {

        bool cond1 = (solve(a.substr(0,i),b.substr(n-i,i))==true) && (solve(a.substr(i,n-i),b.substr(0,n-i))==true);
        bool cond2 = (solve(a.substr(0,i),b.substr(0,i))==true)&&(solve(a.substr(i,n-i),b.substr(i,n-i))==true);

        if(cond1 || cond2)
        {
            flag = true;
            break;
        }    
    }

    return mp[temp]= flag;

}
main()
{
    string a="phqtrnilf";
    string b="ilthnqrpf";

    // cin>>a>>b;

    if(a.length()!=b.length())
        return false;

    if(a.empty()&&b.empty())
        return true;

    cout<<solve(a,b);
}