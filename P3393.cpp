#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
vector<vector<int>>graph;
vector<int>lose_city;
unordered_set<int>danger_city;
vector<long long int>fees;
vector<long long int>fees_sum;
void BFS(int start, int s)
{
    int n = graph.size();
    vector<bool>visit(n,false);
    queue<pair<int, int>>q;
    visit[start] = true;
    q.push(make_pair(start, 0));
    while (q.empty() == false)
    {
        int node = q.front().first;
        int distance = q.front().second;
        q.pop();
        if (distance >= s)
        {
            break;
        }
        for (auto neighbor : graph[node])
        {
            if (visit[neighbor] == false)
            {
                q.push(make_pair(neighbor, distance + 1));
                visit[neighbor] = true;
                if (danger_city.find(neighbor) == danger_city.end())
                {
                    danger_city.insert(neighbor);
                }
            }
        }
    }
}

void BFS2()
{
    queue<int>q;
    q.push(1);
    fees_sum[1] = 0;
    while (q.empty() == false)
    {
        int node = q.front();
        q.pop();
        for (auto nextnode : graph[node])
        {
            if (lose_city[nextnode] == true)
            {
                continue;
            }
            if (fees_sum[nextnode] > fees_sum[node] + fees[nextnode])
            {
                fees_sum[nextnode] = fees_sum[node] + fees[nextnode];
                q.push(nextnode);
            }
        }
    }
}
int main()
{
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    graph.resize(n + 1);
    fees.resize(n + 1);
    fees_sum.resize(n + 1, 10000000001);
    lose_city.resize(n + 1, false);
    int money1, money2;
    cin >> money1 >> money2;
    for (int i = 0; i < k; i++)
    {
        int node;
        scanf("%d", &node);
        lose_city[node] = true;
    }
    for (int i = 0; i < m; i++)
    {
        int u;
        int v;
        scanf("%d%d", &u, &v);
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    //找出所有危险城市
    for (int i=1;i<=n;i++)
    {
        if (lose_city[i] == true)
        {
            BFS(i, s);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (danger_city.find(i) == danger_city.end())
        {
            fees[i] = money1;
        }
        else
        {
            fees[i] = money2;
        }
    }
    fees[1] = 0;
    fees[n] = 0;
    BFS2();
    cout << fees_sum[n];
    return 0;
}