#include <vector>
#include <iostream>
using namespace std;
vector<vector<int>>graph;
vector<pair<int, int>>queries;
vector<int>name_of_points;
void DFS(int u, vector<bool>& visit, int name)
{
    visit[u] = true;
    name_of_points[u] = name;
    for (int i = 0; i < graph[u].size(); i++)
    {
        int v = graph[u][i];
        if (visit[v] == false)
        {
            DFS(v, visit, name);
        }
    }
}
void Print()
{
    for (int i = 0; i < queries.size(); i++)
    {
        int u = queries[i].first;
        int v = queries[i].second;
        if (name_of_points[u] == name_of_points[v])
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
}
int main()
{
    int n;
    int m;
    int p;
    cin >> n >> m >> p;
    graph.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u;
        int v;
        scanf("%d%d", &u, &v);
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    queries.resize(p);
    for (int i = 0; i < p; i++)
    {
        scanf("%d%d", &queries[i].first, &queries[i].second);
    }
    name_of_points.resize(n + 1, -1);
    int name = 1;
    vector<bool>visit(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (visit[i] == false)
        {
            DFS(i, visit, name);
            name++;
        }
    }
    Print();
    return 0;
}