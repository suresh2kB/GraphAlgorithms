#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> Adj;

void bfs(int u, vector<int> &vis)
{
    queue<int> q;
    vis[u] = true;
    q.push(u);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        cout << curr << " ";

        for (int v : Adj[curr])
        {
            if (!vis[v])
            {
                q.push(v);
                vis[v] = true;
            }
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
        Adj.resize(N);
        vector<int> vis(N, 0);
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            Adj[u].push_back(v);
            Adj[v].push_back(u);
        }
        bfs(0, vis);
        cout << endl;
    }
}
