#include <iostream>
#include <vector>
using namespace std;
vector<int>parents;
vector<int>datas;
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
    int preu = u;
    int prev = v;
    u = Find(u);
    v = Find(v);
    if (u != v && datas[preu] != datas[prev])
    {
        if (sizes[u] > sizes[v])
        {
            parents[v] = u;
            sizes[u] += sizes[v];
        }
        else
        {
            parents[u] = v;
            sizes[v] += sizes[u];
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    parents.resize(n * n + 1);
    datas.resize(n * n + 1);
    sizes.resize(n * n + 1, 1);
    vector<pair<int, int>>queries(m);
    for (int i = 1; i <= n * n; i++)
    {
        parents[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 1; j <= n; j++)
        {
            datas[(i - 1) * n + j] = temp[j - 1] - '0';
        }
    }
    for (int i = 0; i < m; i++)
    {
        int u;
        int v;
        cin >> u >> v;
        queries[i] = make_pair(u, v);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i > 1)
            {
                Merge((i - 1) * n + j, (i - 2) * n + j);
            }
            if (i < n)
            {
                Merge((i - 1) * n + j, i * n + j);
            }
            if (j > 1)
            {
                Merge((i - 1) * n + j, (i - 1) * n + j - 1);
            }
            if (j < n)
            {
                Merge((i - 1) * n + j, (i - 1) * n + j + 1);
            }
        }
    }

    for (int i = 0; i < queries.size(); i++)
    {
        int line = queries[i].first;
        int col = queries[i].second;
        cout << sizes[Find((line - 1) * n + col)] << endl;
    }
    return 0;
}

/*
4 3
1010
0101
1000
1110
3 3
2 1
2 4

*/