#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct quere
{
    int u;
    int v;
    int time;
};
vector<int>parents;
vector<int>sizes;
vector<quere>queries;
bool cmp(quere q1, quere q2)
{
    return q1.time < q2.time;
}
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
    parents.resize(n + 1);
    sizes.resize(n + 1, 1);
    queries.resize(m);

    for (int i = 1; i <= n; i++)
    {
        parents[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> queries[i].u >> queries[i].v >> queries[i].time;
    }
    sort(queries.begin(), queries.end(), cmp);

    int mintime = -1;
    for (int i = 0; i < queries.size(); i++)
    {
        int u = queries[i].u;
        int v = queries[i].v;
        int time = queries[i].time;
        Merge(u, v);
        if (sizes[Find(1)] == n)
        {
            mintime = time;
            break;
        }
    }
    cout << mintime;
    return 0;
}