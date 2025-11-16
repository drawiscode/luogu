#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<priority_queue<int,vector<int>,greater<int>>>datas;
int Oper(int count)
{
    int ans = 0;
    if (datas[count].size() == 1)
    {
        return datas[count].top();
    }
    while (datas[count].size() > 2)
    {
        int first = datas[count].top();
        datas[count].pop();
        int second = datas[count].top();
        datas[count].pop();
        datas[count].push(first + second);
    }
    int first = datas[count].top();
    datas[count].pop();
    int second = datas[count].top();
    return max(first, second);
}
int main()
{
    vector<int>ns;
    for (int i = 0; i < 4; i++)
    {
        int n;
        cin >> n;
        ns.emplace_back(n);
    }
    datas.resize(4);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < ns[i]; j++)
        {
            int node;
            cin >> node;
            datas[i].push(node);
        }
    }
    int ans = 0;
    for (int i = 0; i <= 3; i++)
    {
        ans += Oper(i);
    }
    cout << ans;
    return 0;
}