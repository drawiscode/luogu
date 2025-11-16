#include <iostream>
#include <vector>
using namespace std;
vector<vector<vector<pair<int, int>>>>graph;
vector<pair<int, int>>ans;
void DFS(int line, int col, vector<pair<int, int>>& path, vector<bool>& visit, int n)
{
    if (ans.size() == (n * n - n) && n % 2 == 0)
    {
        return;
    }
    if (ans.size() == n * n)
    {
        return;
    }
    if (line == n && col == n)
    {
        if (ans.size() < path.size())
        {
            ans = path;
        }
        return;
    }
    for (int i = 0; i < graph[line][col].size(); i++)
    {
        int nextline = graph[line][col][i].first;
        int nextcol = graph[line][col][i].second;

        //判断这是第几个格子
        int count = min(nextline, line) * n + max(nextcol, col);
        if (visit[count] == false)
        {
            visit[count] = true;
            path.emplace_back(make_pair(nextline, nextcol));

            DFS(nextline, nextcol, path, visit, n);
            //回溯
            visit[count] = false;
            path.pop_back();
        }
    }
}
int main()
{
    int n;
    cin >> n;
    graph.resize(n + 1, vector<vector<pair<int, int>>>(n + 1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                graph[i][j].emplace_back(make_pair(i - 1, j - 1));
            }
            if (i - 1 >= 0 && j + 1 <= n)
            {
                graph[i][j].emplace_back(make_pair(i - 1, j + 1));
            }
            if (i + 1 <= n && j - 1 >= 0)
            {
                graph[i][j].emplace_back(make_pair(i + 1, j - 1));
            }
            if (i + 1 <= n && j + 1 <= n)
            {
                graph[i][j].emplace_back(make_pair(i + 1, j + 1));
            }
        }
    }

    vector<pair<int, int>>path;
    vector<bool>visit(n * n + 1, false);
    DFS(0, 0, path, visit, n);
    //输出
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}