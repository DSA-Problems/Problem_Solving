#include <bits/stdc++.h>
using namespace std;

vector<int> visited(8, 0);
queue<pair<int, int>> q;
bool isThereCycle(int i, vector<int> adj[])
{
    visited[i] = 1;
    q.push({i, 1});

    while (!q.empty())
    {

        int node = q.front().first;
        int previous = q.front().second;
        q.pop();

        for (auto x : adj[node])
        {
            if (!visited[x])
            {
                visited[x] = 1;
                q.push({x, node});
            }
            else if (previous != x)
            {
                return true;
            }
        }
    }
    return false;
}


bool checkFortheCycle(vector<int> adj[],int n){
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
            if (isThereCycle(i, adj))
            {
                return true;
            }
    }

    return false;
}
main()
{
    vector<int> adj[1000];
    adj[1].insert(end(adj[1]), {2});
    adj[2].insert(end(adj[2]), {1,7, 3});
    adj[3].insert(end(adj[3]), {2, 5});
    adj[4].insert(end(adj[4]), {6});
    adj[5].insert(end(adj[5]), {3, 7});
    adj[6].insert(end(adj[6]), {4});
    adj[7].insert(end(adj[7]), {5,2});

    cout<<checkFortheCycle(adj,7);
}