#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> Adj;

void dfs(int u, vector<int> &vis)
{
    vis[u] = true;

    cout << u << " ";

    for (int v : Adj[u])
    {
        if (!vis[v])
        {
            dfs(v, vis);
        }
    }
}
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N, E;
        cin >> N >> E;
        vector<int> vis(N, 0);
        Adj.resize(N);
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            Adj[u].push_back(v);
            Adj[v].push_back(u);
        }

        dfs(0, vis);
    }
}
