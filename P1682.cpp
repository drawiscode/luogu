#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
vector<int>parents;
vector<int>sizes;
vector<vector<int>>girls;
vector<vector<int>>girls_friends;

int Find(int u)
{
    if (u == parents[u])
    {
        return u;
    }
    else
    {
        return Find(parents[u]);
    }
}
void Union(int u, int v)
{

    u = Find(u);
    v = Find(v);
    if (u != v)
    {
        if (sizes[u] > sizes[v])
        {
            sizes[u] += sizes[v];
            parents[v] = u;
        }
        else
        {
            sizes[v] += sizes[u];
            parents[u] = v;
        }
    }
}
int main()
{
    int n, m, k, f;
    cin >> n >> m >> k >> f;
    girls.resize(n + 1);
    parents.resize(n + 1);

    for (int i = 1; i <= n; i++)
    {
        parents[i] = i;
    }

    sizes.resize(n + 1, 1);
    girls_friends.resize(n + 1);

    for (int i = 1; i <= m; i++)
    {
        int boy;
        int girl;
        cin >> girl >> boy;
        girls[girl].emplace_back(boy);
    }
    for (int i = 1; i <= f; i++)
    {
        int u;
        int v;
        cin >> u >> v;
        Union(u, v);
    }

    vector<unordered_set<int>>sets(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int node = Find(i);
        for (auto friends : girls[i])
        {
            if (sets[node].find(friends) == sets[node].end())//需要插入
            {
                sets[node].insert(friends);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int node = Find(i);
        for (auto friends : sets[node])
        {
            girls_friends[i].emplace_back(friends);
        }
    }

    int result = n;
    for (int i = 1; i <= n; i++)
    {
        int girl = parents[i];
        int num_boy = girls_friends[girl].size();
        result = min(result,num_boy);
    }
    if (result + k <= n)
    {
        result += k;
    }
    else
    {
        result = n;
    }
    cout << result;
    return 0;
}