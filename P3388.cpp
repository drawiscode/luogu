#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int>order;
vector<int>minorder;
vector<int>ans;
vector<int>parent;
vector<int>children;
vector<bool>isCutP;
void DFSCV(vector<vector<int>>& graph, vector<bool>& visit, int u, int& time)
{
    visit[u] = true;
    order[u] = time;
    minorder[u]=time;
    time++;
    for (int i = 0; i < graph[u].size(); i++)
    {
        int v = graph[u][i];
        if (visit[v] == false)
        {
            parent[v] = u;
            children[u]++;
            DFSCV(graph, visit, v, time);
            minorder[u]=min(minorder[u],minorder[v]);
            if (parent[u] == -1 && children[u] >= 2)
            {
                isCutP[u] = true;
            }
            else if (parent[u] != -1 && minorder[v] >= order[u])
            {
                isCutP[u] = true;
            }
        }
        else if (parent[u] != v)
        {
            minorder[u] = min(minorder[u], order[v]);
        }
    }
}
int main()
{
    int n;
    int m;
    cin >> n >> m;
    int time = 0;

    order.resize(n + 1, n + 1);
    minorder.resize(n + 1, n + 1);
    parent.resize(n + 1, -1);
    isCutP.resize(n + 1, false);
    children.resize(n + 1, 0);

    vector<vector<int>>graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u;
        int v;
        scanf("%d%d", &u, &v);
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    vector<bool>visit(n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        if(visit[i]==false)
        {
            DFSCV(graph, visit, i, time);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (isCutP[i] == true)
        {
            ans.emplace_back(i);
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        printf("%d ", ans[i]);
    }
    return 0;
}