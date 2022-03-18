#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> Adj;
int Time = 1;

void dfs(int u, vector<int> &low, vector<int> &time, vector<int> &vis, int p)
{
    vis[u] = true;

    low[u] = Time;
    time[u] = Time;
    Time++;

    for (int v : Adj[u])
    {
        if (v == p)
        {
            continue;
        }
        if (!vis[v])
        {
            // If this node is never visited before
            dfs(v, low, time, vis, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= time[u] && p != -1)
            {
                cout << u << " ";
            }
        }
        else
        {
            low[u] = min(low[u], time[v]);
            // If node is visited previously
        }
    }
}
int main()
{
    int N, E;
    cin >> N >> E;
    Adj.resize(N);
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
    vector<int> vis(N, 0);
    vector<int> low(N, 0);
    vector<int> time(N, 0);

    dfs(1, low, time, vis, -1);
}
