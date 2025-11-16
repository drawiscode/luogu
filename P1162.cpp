#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>>datas;
vector<vector<bool>>inside;
vector<vector<bool>>visit;
bool BFS(int i, int j, vector<pair<int, int>>& temp, int n)
{
    visit[i][j] = true;
    if (datas[i][j] != 0)
    {
        return false;
    }
    bool boundary = false;
    bool x1 = false;
    bool x2 = false;
    bool x3 = false;
    bool x4 = false;
    temp.emplace_back(make_pair(i, j));
    if (i == 1 || j == n || i == n || j == 1)
    {
        boundary = true;
    }
    if (visit[i + 1][j] == false)
    {
        x1 = BFS(i + 1, j, temp, n);
    }
    if (visit[i - 1][j] == false)
    {
        x2 = BFS(i - 1, j, temp, n);
    }
    if (visit[i][j + 1] == false)
    {
        x3 = BFS(i, j + 1, temp, n);
    }
    if (visit[i][j - 1] == false)
    {
        x4 = BFS(i, j - 1, temp, n);
    }
    return x1 || x2 || x3 || x4 || boundary;
}
int main()
{
    int n;
    cin >> n;
    datas.resize(n + 2, vector<int>(n + 2, -1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> datas[i][j];
        }
    }
    inside.resize(n + 2, vector<bool>(n + 2, false));
    visit.resize(n + 2, vector<bool>(n + 2, false));
    for (int i = 1; i <= n; i++)
    {
        vector<pair<int, int>>temp;
        for (int j = 1; j <= n; j++)
        {
            if (visit[i][j] == false && datas[i][j] == 0)
            {
                if (!BFS(i, j, temp, n))//ture则是能访问到边界
                {
                    for (int p = 0; p < temp.size(); p++)
                    {
                        int line = temp[p].first;
                        int col = temp[p].second;
                        datas[line][col] = 2;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << datas[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}