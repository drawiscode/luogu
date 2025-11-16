#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;
vector<vector<char>>datas;

vector<tuple<int, int, int>>reach_points;
vector<vector<int>>times;
vector<vector<bool>>can_be_visit;
vector<pair<int, int>>not_reach_place;

void Cal_Which_Can_Be_Visit(int fat_len)
{
    int n = datas.size();
    n--;
    for (int i = 0; i < not_reach_place.size(); i++)
    {
        int line = not_reach_place[i].first;
        int col = not_reach_place[i].second;

        for (int p = max(line - fat_len, 1); p <= min(n, line + fat_len); p++)
        {
            for (int q = max(col - fat_len, 1); q <= min(n, col + fat_len); q++)
            {
                can_be_visit[p][q] = false;
            }
        }
    }
}
void BFS(int k)
{
    int n = datas.size();
    n--;
    queue<tuple<int, int, int>>q;

    vector<vector<bool>>visit(n + 1, vector<bool>(n + 1, false));
    for (int i = 0; i < reach_points.size(); i++)
    {
        int line = get<0>(reach_points[i]);
        int col = get<1>(reach_points[i]);
        int time = get<2>(reach_points[i]);
        q.push(make_tuple(line, col, time));
        visit[line][col] == true;
    }
    reach_points.erase(reach_points.begin(), reach_points.end());

    if (k == 101)
    {
        cout << endl;
    }

    while (q.empty() == false)
    {
        int line = get<0>(q.front());
        int col = get<1>(q.front());
        int time1 = get<2>(q.front());
        q.pop();
        if (line == n - 2 && col == n - 2)//终点
        {
            times[line][col] = min(times[line][col],time1);
            break;
        }

        if (time1 > k)
        {
            break;
        }
        if (line <= 0 || line > n || col <= 0 || col > n || (can_be_visit[line][col] == false))
        {
            continue;
        }

        times[line][col] = min(times[line][col], time1);
        reach_points.emplace_back(make_tuple(line, col, time1));
        if (line + 1 <= n && visit[line + 1][col] == false && can_be_visit[line + 1][col] == true)
        {
            visit[line + 1][col] = true;
            q.push(make_tuple(line + 1, col, time1 + 1));
        }
        if (line - 1 > 0 && visit[line - 1][col] == false && can_be_visit[line - 1][col] == true)
        {
            visit[line - 1][col] = true;
            q.push(make_tuple(line - 1, col, time1 + 1));
        }
        if (col + 1 <= n && visit[line][col + 1] == false && can_be_visit[line][col+1] == true)
        {
            visit[line][col + 1] = true;
            q.push(make_tuple(line, col + 1, time1 + 1));
        }
        if (col - 1 > 0 && visit[line][col - 1] == false && can_be_visit[line][col-1] == true)
        {
            visit[line][col - 1] = true;
            q.push(make_tuple(line, col - 1, time1 + 1));
        }
    }
}

void Print1()
{
    int n = datas.size();
    n--;
    cout << "下面是可以到达的点的信息:" << endl;
    for (int i = 0; i < reach_points.size(); i++)
    {
        int line = get<0>(reach_points[i]);
        int col = get<1>(reach_points[i]);
        int time1 = get<2>(reach_points[i]);
        cout << line << " " << col << " " << time1 << endl;
    }
}
void Print2()
{
    int n = datas.size();
    n--;
    cout << "下面是不可以到达的点的信息:" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << can_be_visit[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    datas.resize(n + 1, vector<char>(n + 1));
    times.resize(n + 1, vector<int>(n + 1, 2 * k + n * n));
    can_be_visit.resize(n + 1, vector<bool>(n + 1, true));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> datas[i][j];
            if (datas[i][j] == '*')
            {
                not_reach_place.emplace_back(make_pair(i, j));
            }
        }
    }
    //下面计算哪些地方无法到达
    for (int j = 0; j <= n; j++)
    {
        not_reach_place.emplace_back(make_pair(0, j));
        not_reach_place.emplace_back(make_pair(n + 1, j));
    }
    for (int i = 0; i <= n; i++)
    {
        not_reach_place.emplace_back(make_pair(i, 0));
        not_reach_place.emplace_back(make_pair(i, n + 1));
    }
    //



    reach_points.emplace_back(make_tuple(3, 3, 0));

    Cal_Which_Can_Be_Visit(2);
    BFS(k);
    if (times[n - 2][n - 2] != 2 * k + n * n)
    {
        cout << times[n - 2][n - 2];
        return 0;
    }


    //重新给reach_points赋值
    vector<tuple<int, int, int>>temp;
    for (int i = 0; i < reach_points.size(); i++)
    {
        int line = get<0>(reach_points[i]);
        int col = get<1>(reach_points[i]);
        temp.emplace_back(make_tuple(line, col, k));
        times[line][col] = k;
    }
    reach_points.erase(reach_points.begin(), reach_points.end());
    reach_points = temp;
    //
   // Print1();
   // Print2();

    can_be_visit.assign(n + 1, vector<bool>(n + 1, true));
    Cal_Which_Can_Be_Visit(1);
    BFS(2 * k);
    if (times[n - 2][n - 2] != 2 * k + n * n)
    {
        cout << times[n - 2][n - 2];
        return 0;
    }

    //重新给reach_points赋值
    temp.erase(temp.begin(), temp.end());
    for (int i = 0; i < reach_points.size(); i++)
    {
        int line = get<0>(reach_points[i]);
        int col = get<1>(reach_points[i]);
        temp.emplace_back(make_tuple(line, col, 2 * k));
        times[line][col] = 2 * k;
    }
    reach_points.erase(reach_points.begin(), reach_points.end());
    reach_points = temp;
    //
   // Print1();
   // Print2();

    can_be_visit.assign(n + 1, vector<bool>(n + 1, true));
    Cal_Which_Can_Be_Visit(0);
    BFS(2 * k + n * n);

    cout << times[n - 2][n - 2];
    return 0;
}

/*
9 10
*+**+++**
+++*+*+**
+*+*+*+**
+**++*+**
+*++*++**
+*+*++***
+*+*+*+**
+*+*+*+**
+++*+++**

*/