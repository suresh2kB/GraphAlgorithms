#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> Adj;
vector<vector<int>> trans;

void dfs(int u, stack<int> &stk, vector<int> &vis)
{
    vis[u] = true;

    for (int v : Adj[u])
    {
        if (!vis[v])
        {
            dfs(v, stk, vis);
        }
    }
    stk.push(u);
}

void dfs1(int u, vector<int> &vis)
{
    vis[u] = true;

    cout << u << " ";
    for (int v : trans[u])
    {
        if (!vis[v])
        {
            dfs1(v, vis);
        }
    }
}

int main()
{
    int N, E;
    cin >> N >> E;
    Adj.resize(N);
    trans.resize(N);
    vector<int> vis(N, 0);

    stack<int> stk;

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        Adj[u].push_back(v);
    }

    for (int i = 1; i < N; i++)
    {
        if (!vis[i])
        {
            dfs(i, stk, vis);
        }
    }

    // while (!stk.empty())
    // {
    //     cout << stk.top() << " ";
    //     stk.pop();
    // }
    for (int i = 1; i < N; i++)
    {
        vis[i] = false;
        for (int v : Adj[i])
        {
            trans[v].push_back(i);
        }
    }

    while (!stk.empty())
    {
        int u = stk.top();
        stk.pop();

        if (!vis[u])
        {
            cout << "SCC : ";
            dfs1(u, vis);
            cout << endl;
        }
    }
}
