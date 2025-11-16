#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
using namespace std;
vector<vector<int>>graph;
vector<int>dists;

vector<int>d;//以i为根的子树的所以结点数

int point;//树的重心
int mins = 50001;

void DFS(int u, int parent)
{
    d[u] = 1;
    int ans = 0;//u结点的最大子树大小
    for (int i = 0; i < graph[u].size(); i++)
    {
        int v = graph[u][i];
        if (v == parent)
        {
            continue;
        }
        DFS(v, u);
        d[u] += d[v];
        ans = max(ans, d[v]);
    }
    int n = graph.size() - 1;
    ans = max(ans, n - d[u]);
    if (mins > ans||(mins==ans&&point>u))
    {
        mins = ans;
        point = u;
    }
}

void BFS(int u, vector<bool>& visit)
{
    visit[u] = true;
    for (int i = 0; i < graph[u].size(); i++)
    {
        int v = graph[u][i];
        if (visit[v] == false)
        {
            dists[v] = min(dists[v], dists[u] + 1);
            BFS(v, visit);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    graph.resize(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int u;
        int v;
        scanf("%d%d", &u, &v);
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    //求树的重心
    d.resize(n + 1, 0);
 
    DFS(1, 0);

    //
    dists.resize(n + 1, n);
    dists[point] = 0;
    vector<bool>visit(n + 1, false);
    visit[point] = true;
    BFS(point, visit);
    long long int sum = accumulate(dists.begin() + 1, dists.end(), 0);
    cout << point << " " << sum;
    return 0;
}