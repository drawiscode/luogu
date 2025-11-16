#include <iostream>
#include <vector>
using namespace std;
vector<int>fathers;
vector<int>sizes;
int Find(int u)
{
    if (fathers[u] == u)
    {
        return u;
    }
    else
    {
        return Find(fathers[u]);
    }
}
void Merge(int u, int v)
{
    int parent_u = Find(u);
    int parent_v = Find(v);
    if (parent_u != parent_v)
    {
        if (sizes[parent_u] > sizes[parent_v])
        {
            fathers[parent_v] = parent_u;
            sizes[parent_u] += sizes[parent_v];
        }
        else
        {
            fathers[parent_u] = parent_v;
            sizes[parent_v] += sizes[parent_u];
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    fathers.resize(n + 1);
    sizes.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        fathers[i] = i;
        sizes[i] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        int operators;
        int u;
        int v;
        cin >> operators >> u >> v;
        if (operators == 1)
        {
            Merge(u, v);
        }
        else
        {
            if (Find(u) == Find(v))
            {
                cout << "Y" << endl;
            }
            else
            {
                cout << "N" << endl;
            }
        }
    }
    return 0;
}