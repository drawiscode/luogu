#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>>graph;
vector<bool>visit;
vector<int>parent;
vector<int>children;
vector<int>low;
vector<int>d;
vector<vector<int>>ans;
vector<pair<int, int>>cut_edges;

void DFSCE(int u, int &time)
{
    visit[u] = true;
    low[u] = time;
    d[u] = time;
    time++;
    for (int i = 0; i < graph[u].size(); i++)
    {
        int v = graph[u][i];
        if (visit[v] == false)
        {
            children[u]++;
            parent[v] = u;
            DFSCE(v, time);
            low[u] = min(low[u], low[v]);
            if (low[v] > d[u])
            {
                cut_edges.emplace_back(make_pair(u, v));
            }
        }
        else if (parent[u] != v)
        {
            low[u] = min(low[u], d[v]);
        }
    }
}
void DFS(int u, vector<int>& temp)
{
    visit[u] = true;
    temp.emplace_back(u);
    for (int i = 0; i < graph[u].size(); i++)
    {
        int v = graph[u][i];
        if (visit[v] == false)
        {
            DFS(v, temp);
        }
    }
}

void Delete_Edge(int u, int v)
{
    for (int i = 0; i < graph[u].size(); i++)
    {
        if (graph[u][i] == v)
        {
            graph[u].erase(graph[u].begin() + i);
            break;
        }
    }
    for (int i = 0; i < graph[v].size(); i++)
    {
        if (graph[v][i] == u)
        {
            graph[v].erase(graph[v].begin() + i);
            break;
        }
    }
}

void Delete_Edges()
{
    for (int i = 0; i < cut_edges.size(); i++)
    {
        int u = cut_edges[i].first;
        int v = cut_edges[i].second;
        Delete_Edge(u, v);
    }
    return;
}
int main()
{
    int n;
    int m;
    cin >> n >> m;

    graph.resize(n + 1);
    visit.resize(n + 1, false);
    parent.resize(n + 1, -1);
    children.resize(n + 1, 0);
    d.resize(n + 1);
    low.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u;
        int v;
        scanf("%d%d", &u, &v);
        if (u == v)
        {
            graph[u].emplace_back(v);
            continue;
        }
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    //找割边
    int time = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visit[i] ==false)
        {
            DFSCE(i, time);
        }
    }


    /*cout << endl;
    for (int i = 0; i < cut_edges.size(); i++)
    {
        cout << cut_edges[i].first << " " << cut_edges[i].second << endl;
    }
    cout << endl;*/

    Delete_Edges();

    visit.assign(n + 1, false);

    //DFS
    for (int i = 1; i <= n; i++)
    {
        if (visit[i] == false)
        {
            vector<int>temp;
            DFS(i, temp);
            ans.emplace_back(temp);
        }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++)
    {
        printf("%d ", ans[i].size());
        for (int j = 0; j < ans[i].size(); j++)
        {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}