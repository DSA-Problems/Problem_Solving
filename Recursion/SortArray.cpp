#include <bits/stdc++.h>
using namespace std;

// To insert the popped element in apropirate place
void Insert(vector<int> &v, int temp)
{
    if (v.size() == 0 || v[v.size() - 1] <= temp)
    {
        v.push_back(temp);
        return;
    }
    int tempval = v[v.size() - 1];
    v.pop_back();

    Insert(v, temp);
    
    v.push_back(tempval);
}

//To sort the array 
void sort(vector<int> &v)
{
    if (v.size() == 1)
        return;

    int temp = v[v.size() - 1];
    v.pop_back();

    sort(v);

    Insert(v, temp);
}

main()
{
    vector<int> v = {1, 5, 0, 7, 5};

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ",";
    sort(v);
    cout << endl;
    cout<<"--> Sorted Array : ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ",";
}