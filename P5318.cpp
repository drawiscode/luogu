#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
void DFS(vector<vector<int>>& graph, vector<bool>& visit, int start)
{
    printf("%d ", start);
    visit[start] = true;
    for (int i = 0; i < graph[start].size(); i++)
    {
        int v = graph[start][i];
        if (visit[v] == false)
        {
            DFS(graph, visit, v);
        }
    }
}
void BFS(vector<vector<int>>& graph, vector<bool>& visit)
{
    queue<int>q;
    q.push(1);
    visit[1] = true;
    while (q.empty() == false)
    {
        int node = q.front();
        q.pop();
        printf("%d ", node);
        for (int i = 0; i < graph[node].size(); i++)
        {
            int v = graph[node][i];
            if (visit[v] == false)
            {
                q.push(v);
                visit[v] = true;
            }
        }
    }
}
int main()
{
    int n;
    int m;
    cin >> n >> m;
    vector<vector<int>>graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u;
        int v;
        scanf("%d%d", &u, &v);
        graph[u].emplace_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(graph[i].begin(), graph[i].end(), less<int>());
    }
    vector<bool>visit(n + 1, false);
    DFS(graph, visit, 1);
    cout << endl;
    visit.assign(n + 1, false);
    BFS(graph, visit);
    return 0;

}