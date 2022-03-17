#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> Adj;

int main()
{
    int N, E;
    cin >> N >> E;
    Adj.resize(N);

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        Adj[u].push_back({v, w});
        Adj[v].push_back({u, w});
    }
    int parent[N];
    int key[N];
    bool mstSet[N];

    for (int i = 0; i < N; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;
    parent[0] = -1;
    pq.push({0, 0});

    for (int counts = 0; counts < N - 1; counts++)
    {

        int u = pq.top().second;
        pq.pop();
        mstSet[u] = true;

        for (auto it : Adj[u])
        {
            int v = it.first;
            int w = it.second;
            if (mstSet[v] == false && key[v] > w)
            {
                key[v] = w;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    for (int i = 1; i < N; i++)
    {
        cout << parent[i] << " - " << i << endl;
    }
}
