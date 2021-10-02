#include<bits/stdc++.h>
using namespace std;


vector<int> visited(8,0);
vector<int> DFS;
void DFSTraverse(int i,vector<int> adj[])
{
    DFS.push_back(i);
    visited[i]=1;

    for(auto it:adj[i])
    {
        if(visited[it]==0)
        {
            DFSTraverse(it,adj);
        }
    }
}
main()
{
    vector<int> adj[1000]; 
    adj[1].insert(end(adj[1]), {2});
    adj[2].insert(end(adj[2]), {1,3,7});
    adj[3].insert(end(adj[3]), {2,5});
    adj[4].insert(end(adj[4]), {6});
    adj[5].insert(end(adj[5]), {3,7});
    adj[6].insert(end(adj[6]), {4});
    adj[7].insert(end(adj[7]), {2,5});


    for(int i=1;i<=7;i++)
    {
        if(visited[i]==0)
            DFSTraverse(i,adj);
    }

    cout<<"--> DFS Traversal : ";
    for(auto x:DFS)
    {
        cout<<x<<" , ";
    }
}