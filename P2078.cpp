#include <iostream>
#include <vector>
using namespace std;
vector<int>pa_A;
vector<int>pa_B;
vector<int>sizes_A;
vector<int>sizes_B;
int Find_A(int u)
{
    if (u == pa_A[u])
    {
        return u;
    }
    else
    {
        return Find_A(pa_A[u]);
    }
}
int Find_B(int u)
{
    if (u == pa_B[u])
    {
        return u;
    }
    else
    {
        return Find_B(pa_B[u]);
    }
}
void Merge_A(int u, int v)
{
    u = Find_A(u);
    v = Find_A(v);
    if (u != v)
    {
        if (sizes_A[u] > sizes_A[v])
        {
            pa_A[v] = u;
            sizes_A[u] += sizes_A[v];
        }
        else
        {
            pa_A[u] = v;
            sizes_A[v] += sizes_A[u];
        }
    }
}
void Merge_B(int u, int v)
{
    u = Find_B(u);
    v = Find_B(v);
    if (u != v)
    {
        if (sizes_B[u] > sizes_B[v])
        {
            pa_B[v] = u;
            sizes_B[u] += sizes_B[v];
        }
        else
        {
            pa_B[u] = v;
            sizes_B[v] += sizes_B[u];
        }
    }
}

int main()
{
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    pa_A.resize(n + 1);
    pa_B.resize(m + 1);
    sizes_A.resize(n + 1, 1);
    sizes_B.resize(m + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        pa_A[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        pa_B[i] = i;
    }

    for (int i = 0; i < p; i++)
    {
        int u;
        int v;
        cin >> u >> v;
        if (u != v)
        {
            Merge_A(u, v);
        }
    }
    for (int i = 0; i < q; i++)
    {
        int u;
        int v;
        cin >> u >> v;
        if (u != v)
        {
            Merge_B(-u, -v);
        }
    }
    cout << min(sizes_A[Find_A(1)],sizes_B[Find_B(1)]);
    return 0;
}