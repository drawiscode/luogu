#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
using namespace std;
vector<int>datas;
vector<vector<pair<int, int>>>graph;
vector<pair<int, int>>graph_sort;
vector<vector<int>>dists;

bool cmp(pair<int, int>&data1, pair<int, int>&data2)
{
    int time1 = data1.second;
    int time2 = data2.second;
    return time1 < time2;
}

void update(int k)
{
    int n = graph.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
            dists[j][i] = min(dists[j][i], dists[j][k] + dists[k][i]);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    datas.resize(n);

    dists.resize(n, vector<int>(n, 200000000));

    for (int i = 0; i < n; i++)
    {
        cin >> datas[i];
        graph_sort.emplace_back(make_pair(i, datas[i]));
        dists[i][i] = 0;
    }

    sort(graph_sort.begin(), graph_sort.end(), cmp);
    graph.resize(n);
    for (int i = 0; i < m; i++)
    {
        int u;
        int v;
        int val;
        cin >> u >> v >> val;
        graph[u].emplace_back(make_pair(v, val));
        graph[v].emplace_back(make_pair(u, val));
        dists[u][v] = val;
        dists[v][u] = val;
    }
    int q;
    cin >> q;
    vector<vector<int>>queries(q, vector<int>(3));
    for (int i = 0; i < q; i++)
    {
        int x, y, t;
        cin >> x >> y >> t;
        queries[i][0] = x;
        queries[i][1] = y;
        queries[i][2] = t;
    }

    int k = 0;
    for (int i = 0; i < q; i++)
    {
        int x = queries[i][0];
        int y = queries[i][1];
        int t = queries[i][2];
        while (k != n && t >= graph_sort[k].second)
        {
            update(k);
            k++;
        }
        if (t < datas[x] || t < datas[y] || dists[x][y] == 200000000)
        {
            cout << -1 << endl;
        }
        else 
        {
            cout << dists[x][y] << endl;
        }
    }

    return 0;
}
/*
4 5
1 2 3 4
0 2 1
2 3 1
3 1 2
2 1 4
0 3 5
4
2 0 2
0 1 2
0 1 3
0 1 4
*/



/*#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;
vector<int>datas;
vector<vector<pair<int, int>>>graph;

int Dijkstra(int x, int y, int t)
{
    if (datas[x] > t)
    {
        return -1;
    }
    int n = graph.size();
    vector<int>dists(n, INT32_MAX);
    vector<int>N(n, false);
    vector<int>S(n, false);
    S[x] = true;
    dists[x] = 0;
    int u = x;
    while (1)
    {
        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i].first;
            if (S[v] == false && t >= datas[v])
            {
                N[v] = true;
                int val = graph[u][i].second;
                dists[v] = min(dists[v], dists[u] + val);
            }
        }
        int minlen = INT32_MAX;
        for (int i = 0; i < n; i++)
        {
            if (N[i] == true && S[i] == false)
            {
                if (minlen > dists[i])
                {
                    minlen = dists[i];
                    u = i;
                }
            }
        }
        S[u] = true;
        if (minlen == INT32_MAX)
        {
            break;
        }
    }
    if (dists[y] == INT32_MAX)
    {
        return -1;
    }
    else
    {
        return dists[y];
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    graph.resize(n);
    datas.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> datas[i];
    }
    for (int i = 0; i < m; i++)
    {
        int u;
        int v;
        int val;
        cin >> u >> v >> val;
        graph[u].emplace_back(make_pair(v, val));
        graph[v].emplace_back(make_pair(u, val));
    }
    int q;
    cin >> q;
    vector<vector<int>>queries(q, vector<int>(3));
    for (int i = 0; i < q; i++)
    {
        int x, y, t;
        cin >> x >> y >> t;
        queries[i][0] = x;
        queries[i][1] = y;
        queries[i][2] = t;
    }

    for (int i = 0; i < q; i++)
    {
        int x = queries[i][0];
        int y = queries[i][1];
        int t = queries[i][2];
        int ans = Dijkstra(x, y, t);
        cout << ans << endl;
    }

    return 0;
}*/
/*
4 5
1 2 3 4
0 2 1
2 3 1
3 1 2
2 1 4
0 3 5
1
2 0 2


*/