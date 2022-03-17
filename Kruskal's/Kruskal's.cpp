#include <bits/stdc++.h>
using namespace std;
vector<int> Rank;
vector<int> Parent;

int findPar(int u)
{
    if(u==Parent[u])
    {
        return u;
    }

    return Parent[u] = findPar(Parent[u]);
}


void Union(int u,int v)
{
    u = findPar(u);
    v = findPar(v);

    if(Rank[u]>Rank[v])
    {
        Parent[v] = u;
    }
    else if(Rank[u]<Rank[v])
    {
        Parent[u] = v;
    }
    else{
        Parent[v] = u;
        Rank[u]++;
    }
}
bool comp(pair<pair<int, int>, int> &first1, pair<pair<int, int>, int> &second1)
{
    return first1.second < second1.second;
}
int main()
{
    int N, E;
    cin >> N >> E;

    Rank.resize(N);
    Parent.resize(N);

    for (int i = 0; i < N; i++)
    {
        Rank[i] = 0;
        Parent[i] = i;
    }
    vector<pair<pair<int, int>, int>> edges;

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({{u, v}, w});
    }

    sort(edges.begin(), edges.end(), comp);
    vector<pair<int,int>> MST;
    int sum=0;

    for(int i=0;i<E;i++){
        // cout<<edges[i].first.first<<" "<<edges[i].first.second<<" "<<edges[i].second<<endl;
        int u = edges[i].first.first;
        int v = edges[i].first.second;
        int w = edges[i].second;

        if(findPar(u)==findPar(v))
        {
            continue;
        }
        else{
            MST.push_back({u,v});
            sum+=w;
            Union(u,v);
        }
    }

    cout<<sum<<endl;
    for(int i=0;i<MST.size();i++){
        cout<<MST[i].first<<" "<<MST[i].second<<endl;
    }
}
