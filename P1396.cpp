#include <iostream>
#include <vector>
using namespace std;
vector<vector<pair<int, int>>>graph;
vector<int>dists;
int main()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    graph.resize(n + 1);
    dists.resize(n + 1, 10001);
    for (int i = 0; i < m; i++)
    {
        int u;
        int v;
        int w;
        cin >> u >> v >> w;
        graph[u].emplace_back(make_pair(v, w));
        graph[v].emplace_back(make_pair(u, w));
    }

    //
    vector<bool>S(n + 1, false);
    dists[s] = 0;
    S[s] = true;
    int cur = s;
    while (1)
    {
        S[cur] = true;
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int v = graph[cur][i].first;
            if (S[v] == false)
            {
                dists[v] = min(dists[v], max(dists[cur], graph[cur][i].second));
            }
        }
        int mindist = 10001;
        for (int i = 1; i <= n; i++)
        {
            if (S[i] == false)
            {
                if (mindist > dists[i])
                {
                    mindist = dists[i];
                    cur = i;
                }
            }
        }
        if (cur == t)
        {
            break;
        }
    }
    cout << dists[t];
    return 0;
}