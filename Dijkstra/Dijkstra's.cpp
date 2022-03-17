#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> Adj;
int main()
{
    int N, E;
    cin >> N >> E;
    // N++;
    Adj.resize(N);
    vector<int> dis(N, INT_MAX);

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        Adj[u].push_back({v, w});
        Adj[v].push_back({u, w});
    }

    cout << "Enter Source " << endl;
    int s;
    cin >> s;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dis[s] = 0;
    pq.push({0, s});

    while (!pq.empty())
    {
        auto it = pq.top();
        int dist = it.first;
        int u = it.second;
        cout << u << " " << dist << endl;
        pq.pop();

        for (auto it1 : Adj[u])
        {
            int v = it1.first;
            int curr_dist = it1.second;

            if (dist + curr_dist < dis[v])
            {
                dis[v] = dist + curr_dist;
                pq.push({dis[v], v});
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << dis[i] << " ";
    }
}
