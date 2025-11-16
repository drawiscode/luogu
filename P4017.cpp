#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>>graph;
vector<int>degrees_in;
vector<int>degrees_out;
vector<int>path;
int main()
{
    int n;
    int m;
    cin >> n >> m;
    graph.resize(n + 1);
    degrees_in.resize(n + 1, 0);
    degrees_out.resize(n + 1, 0);
    path.resize(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int u;
        int v;
        cin >> u >> v;
        degrees_in[v]++;
        degrees_out[u]++;
        graph[u].emplace_back(v);
    }

    queue<int>q;
    vector<int>consume;
    for (int i = 1; i <= n; i++)
    {
        if (degrees_in[i] == 0)
        {
            q.push(i);
            path[i] = 1;
        }
        if (degrees_out[i] == 0)
        {
            consume.emplace_back(i);
        }
    }

    while (q.empty() == false)
    {
        int node = q.front();
        q.pop();
        for (int i = 0; i < graph[node].size(); i++)
        {
            int v = graph[node][i];
            path[v] = (path[v] + path[node]) % 80112002;
            degrees_in[v]--;
            if (degrees_in[v] == 0)
            {
                q.push(v);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < consume.size(); i++)
    {
        ans = (ans + path[consume[i]]) % 80112002;
    }
    cout << ans;
    return 0;
}