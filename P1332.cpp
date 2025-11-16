#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
vector<pair<int, int>>gan_ran_yuan;
vector<pair<int, int>>people;
vector<vector<int>>results;
void BFS(int line, int col, int n)
{
    queue<tuple<int, int, int>>q;
    vector<vector<int>>visit(n + 1, vector<int>(n + 1, false));
    q.push(make_tuple(line, col, 0));
    while (q.empty() == false)
    {
        int i = get<0>(q.front());
        int j = get<1>(q.front());
        int time = get<2>(q.front());
        q.pop();
        if ((!(i <= 0 || j <= 0 || i > n || j > n)) && visit[i][j] == false)
        {
            visit[i][j] = true;
            results[i][j] = min(results[i][j], time);
            q.push(make_tuple(i + 1, j, time + 1));
            q.push(make_tuple(i - 1, j, time + 1));
            q.push(make_tuple(i, j + 1, time + 1));
            q.push(make_tuple(i, j - 1, time + 1));
        }
    }
}
int main()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    gan_ran_yuan.resize(a);
    people.resize(b);
    for (int i = 0; i < a; i++)
    {
        int line;
        int col;
        scanf("%d%d", &line, &col);
        gan_ran_yuan[i] = make_pair(line, col);
    }
    for (int i = 0; i < b; i++)
    {
        int line;
        int col;
        scanf("%d%d", &line, &col);
        people[i] = make_pair(line, col);
    }


    results.resize(n + 1, vector<int>(n + 1, n + m + 3));
    for (int i = 0; i < gan_ran_yuan.size(); i++)
    {
        int line = gan_ran_yuan[i].first;
        int col = gan_ran_yuan[i].second;
        BFS(line, col, n);
    }

    for (int i = 0; i < people.size(); i++)
    {
        int line = people[i].first;
        int col = people[i].second;
        printf("%d\n", &results[line][col]);
    }
    return 0;
}
