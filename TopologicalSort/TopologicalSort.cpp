#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> Adj;
stack<int> topo;

void dfs(int u, vector<int> &vis)
{
    vis[u] = true;

    for (int v : Adj[u])
    {
        if (!vis[v])
        {
            dfs(v, vis);
        }
    }

    topo.push(u);
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, E;
        cin >> N >> E;
        Adj.resize(N);
        vector<int> vis(N, 0);
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            Adj[u].push_back(v);
        }

        for (int i = 0; i < N; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis);
            }
        }

        while (!topo.empty())
        {
            cout << topo.top() << " ";
            topo.pop();
        }
    }
}
