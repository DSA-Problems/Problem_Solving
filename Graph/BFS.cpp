#include<bits/stdc++.h>
using namespace std;


vector<int> visited(7,0);
vector<int> BFS;


void BFSTraverse(int i,vector<int> adj[])
{
        queue<int> q;
        q.push(i);
        visited[i]=1;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            BFS.push_back(node);

            for(auto it:adj[node])
            {
                if(visited[it]!=1)
                    {
                        q.push(it);
                        visited[it]=1;
                    }
            }
        }
}
main()
{
    // Input
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
            BFSTraverse(i,adj);
    }

    cout<<"--> BFS Traversal : ";
    for(auto x:BFS)
    {
        cout<<x<<" , ";
    }
}
