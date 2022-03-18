#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> Adj;

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
}
bool Connected_Graph()
{
    int n = Adj.size();
    vector<int> vis(n + 1, 0);
    int node = -1;

    for (int i = 0; i < n; i++)
    {
        if (Adj[i].size() > 0)
        {
            node = i;
            break;
        }
    }

    if (node == -1)
    {
        return true;
    }

    dfs(node, vis);

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false && Adj[i].size() > 0)
        {
            return false;
        }
    }

    return true;
}
int find_Eular()
{
    if (!Connected_Graph())
    {
        return 0;
    }

    int odd = 0;

    for (int i = 0; i < Adj.size(); i++)
    {
        if (Adj[i].size() % 2 != 0)
        {
            odd++;
        }
    }

    if (odd > 2)
    {
        return 0;
    }

    return (odd == 0) ? 2 : 1;
}

void findEular_PAth_Cycle()
{
    int res = find_Eular();

    if (res == 0)
    {
        cout << "Graph is NOT a Eular graph" << endl;
    }
    else if (res == 1)
    {
        cout << "Graph is Semi-Eularian graph" << endl;
    }
    else
    {
        cout << "Graph is a Eular graph" << endl;
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
    findEular_PAth_Cycle();
}
