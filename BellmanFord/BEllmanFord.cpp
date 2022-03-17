#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, E;
    cin >> N >> E;
    vector<pair<pair<int, int>, int>> edges;
    vector<int> dis(N + 1, 10000000);

    // If there is any negative edges weight in undirected graph then
    // Dijkstra and Bellman ford cannot find SSSP

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({{u, v}, w});
    }
    cout << "Enter source vertex " << endl;
    int s;
    cin >> s;
    dis[s] = 0;

    for (int k = 0; k < N - 1; k++)
    {
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i].first.first;
            int v = edges[i].first.second;
            int w = edges[i].second;

            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
            }
        }
    }

    // To check for negative edge weight cycle run one more time inner loop and
    // if distance value changes for any of the node then there will be atleast
    // one negative edges weight cylce

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first.first;
        int v = edges[i].first.second;
        int w = edges[i].second;
        if (dis[v] > dis[u] + w)
        {
            cout << "There is atleat one negative edges weight cycle" << endl;
            return 0;
        }
    }
    // cout << N << endl;
    for (int i = 0; i < N + 1; i++)
    {
        cout << dis[i] << " ";
    }
    cout << endl;
    cout << "There is NO negative edges weight cycle" << endl;
    return 0;
}
