#include <bits/stdc++.h>
using namespace std;
vector<int> parent;
vector<int> Rank;

int findPar(int u)
{
    if (parent[u] == u)
    {
        return u;
    }

    return parent[u] = findPar(parent[u]);
}

void Union(int u, int v)
{
    u = findPar(u);
    v = findPar(v);

    if (Rank[u] > Rank[v])
    {
        parent[v] = u;
    }
    else if (Rank[u] < Rank[v])
    {
        parent[u] = v;
    }
    else
    {
        parent[v] = u;
        Rank[u]++;
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
        parent.resize(N);
        Rank.resize(N);

        for (int i = 0; i < N; i++)
        {
            parent[i] = i;
            Rank[i] = 0;
        }
        bool cycle = false;
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;

            int paru = findPar(u);
            int parv = findPar(v);

            if (paru == parv)
            {
                cout << "There is an cycle in graph" << endl;
                cycle = true;
                break;
            }
            else
            {
                Union(u, v);
            }
        }
        if (!cycle)
        {
            cout << "There is no cycle in Graph" << endl;
        }
    }
}
