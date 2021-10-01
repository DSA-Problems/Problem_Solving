#include<bits/stdc++.h>
using namespace std;

unordered_map<string,int> mp;
int solve (string s,int i,int j,bool istrue)
{
    if(i>j)
        return false;
    if(i==j)
        if(istrue==true)
            return s[i]=='T';
        else    
            return s[i]=='F';

    string temp=to_string(i)+" "+to_string(j)+" "+to_string(istrue);

    if(mp.find(temp)!=mp.end())
        {
            return mp[temp];
        }



    int ans = 0;
    for(int k=i+1;k<=j-1;k=k+2)
    {
        int lt = solve(s,i,k-1,true);
        int lf = solve(s,i,k-1,false);
        int rt = solve(s,k+1,j,true);
        int rf = solve(s,k+1,j,false);

 
        if(s[k]=='&')
        {
            if(istrue==true)
                ans = ans + lt*rt;
            else
                ans = ans + lf*rt + lt*rf + lf*rf;
        }
        else if(s[k]=='|')
        {
            if(istrue==true)
                ans = ans + lt*rf + lt*rt + lf*rt;
            else
                ans = ans + rf*lf;
        }
        else if(s[k]=='^')
        {
            if(istrue==true)
                ans = ans + lf*rt + lt*rf;
            else    
                ans = ans + lt*rt+lf*rf;
        }

    }
    
    return mp[temp]= ans;
}   
main()
{
    string s = "T|T&F^T";
    // There are 4 ways
    // ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and
    // (T|((T&F)^T))

    mp.clear();
    cout<<solve(s,0,s.length()-1,true);
}