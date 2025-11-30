#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>>datas;
void Mul(vector<int>& tempi, int pre, vector<int>& push_temp)
{
    for (int i = 0; i < datas[pre].size(); i++)
    {
        for (int j = 0; j < tempi.size(); j++)
        {
            push_temp[i + j] += tempi[j] * datas[pre][i];
        }
    }
    for (int i = 0; i < push_temp.size(); i++)
    {
        if (push_temp[i] >= 10)
        {
            push_temp[i + 1] += push_temp[i] / 10;
            push_temp[i] = push_temp[i] % 10;
        }
    }
}
void Add(int cur, vector<int>& ans)
{
    for (int i = 0; i < datas[cur].size(); i++)
    {
        ans[i] += datas[cur][i];
    }
}
void Print(int node)
{
    int i = datas[node].size() - 1;
    while (datas[node][i] == 0)
    {
        i--;
    }
    while (i >= 0)
    {
        cout << datas[node][i];
        i--;
    }
    return;
}
int main()
{
    int n;
    cin >> n;
    vector<int>temp;
    datas.emplace_back(temp);
    vector<int>temp1;
    temp1.emplace_back(1);
    datas.emplace_back(temp1);
    for (int i = 2; i <= n; i++)
    {
        vector<int>tempi;
        int cur = i;
        while (cur != 0)
        {
            tempi.emplace_back(cur % 10);
            cur = cur / 10;
        }
        vector<int>push_temp(datas[i - 1].size() + 2, 0);
        Mul(tempi, i - 1, push_temp);
        datas.emplace_back(push_temp);
    }

    /*for (int i = 1; i <= n; i++)
    {
        Print(i);
        cout << endl;
    }*/

    vector<int>ans(datas[n].size() + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        Add(i, ans);
    }
    for (int i = 0; i < ans.size() - 1; i++)
    {
        if (ans[i] >= 10)
        {
            ans[i + 1] += ans[i] / 10;
            ans[i] = ans[i] % 10;
        }
    }
    int p = ans.size() - 1;
    while (ans[p] == 0)
    {
        p--;
    }
    while (p >= 0)
    {
        cout << ans[p];
        p--;
    }
    return 0;
}