#include <iostream>
#include <vector>
using namespace std;
vector<vector<char>>datas;
vector<vector<bool>>visit;
void BFS(int i, int j, vector<pair<int, int>>& temp)
{
    int n = datas.size();
    int m = datas[0].size();
    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        return;
    }
    if (visit[i][j] == true || datas[i][j] != '#')
    {
        return;
    }
    visit[i][j] = true;
    temp.emplace_back(i, j);
    BFS(i + 1, j, temp);
    BFS(i - 1, j, temp);
    BFS(i, j + 1, temp);
    BFS(i, j - 1, temp);
}
int main()
{
    int n, m;
    cin >> n >> m;
    datas.resize(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> datas[i][j];
        }
    }
    visit.resize(n, vector<bool>(m));
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visit[i][j] == false && datas[i][j] == '#')
            {
                vector<pair<int, int>>temp;
                BFS(i, j, temp);
                int maxline = 0;
                int minline = n;
                int maxcol = 0;
                int mincol = m;
                for (int p = 0; p < temp.size(); p++)
                {
                    maxline = max(maxline, temp[p].first);
                    minline = min(minline, temp[p].first);
                    maxcol = max(maxcol, temp[p].second);
                    mincol = min(mincol, temp[p].second);
                }
                if ((maxline - minline + 1) * (maxcol - mincol + 1) != temp.size())
                {
                    cout << "Bad placement.";
                    return 0;
                }
                count++;
            }
        }
    }
    cout << "There are " << count << " ships.";
    return 0;
}
/*
3 4
...#
##..
##..
*/