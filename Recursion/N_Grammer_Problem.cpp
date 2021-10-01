#include<bits/stdc++.h>
using namespace std;

/*
N-Grammer problem 


        0 
        0 1
        0 1 1 0
        0 1 1 0 1 0 0 1


*/

int grammer(int n,int k)
{
    if(n==1||k==1)
        return 0;

        int mid = pow(2,n-1)/2;

        if(k<=mid)
            return grammer(n-1,k);
        else    
            return !grammer(n-1,k-mid);
}
main(){

    int n = 4;
    int k = 2;

    cout<<grammer(n,k);
}