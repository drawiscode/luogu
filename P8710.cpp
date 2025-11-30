#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
vector<int>parents;
vector<unordered_set<int>>sets;
vector<int>vals;
vector<int>sizes;
int Find(int u)
{
    if (parents[u] == u)
    {
        return u;
    }
    else
    {
        return Find(parents[u]);
    }
}
void Merge(int u, int v)
{
    u = Find(u);
    v = Find(v);
    if (u != v)
    {
        if (sizes[u] < sizes[v])
        {
            parents[u] = v;
            sizes[v] += sizes[u];
            for (auto num : sets[u])
            {
                sets[v].insert(num);
            }
        }
        else
        {
            parents[v] = u;
            sizes[u] += sizes[v];
            for (auto num : sets[v])
            {
                sets[u].insert(num);
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    parents.resize(n + 1);
    sets.resize(n + 1);
    vals.resize(n + 1, 0);
    sizes.resize(n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        parents[i] = i;
        sets[i].insert(i);
    }
    for (int i = 0; i < m; i++)
    {
        int operators;
        cin >> operators;
        if (operators == 1)
        {
            int u;
            int v;
            cin >> u >> v;
            Merge(u, v);
        }
        else
        {
            int node;
            int t;
            cin >> node >> t;
            node = Find(node);
            for (auto num : sets[node])
            {
                vals[num] += t;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << vals[i] << " ";
    }
    return 0;
}