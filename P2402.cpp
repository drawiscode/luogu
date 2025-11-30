#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>datas;
vector<vector<int>>ans;
bool cmp(vector<int>data1, vector<int>data2)
{
    int n1 = data1.size();
    int n2 = data2.size();
    int n = min(n1, n2);
    for (int i = 0; i < n; i++)
    {
        if (data1[i] > data2[i])
        {
            return false;
        }
        else if (data1[i] < data2[i])
        {
            return true;
        }
    }
    return false;
}
void TraceBack(int u, int start, int presum,int n)
{
    if (presum == n && u == n)
    {
        ans.emplace_back(datas);
        return;
    }
    if (u >= n)
    {
        return;
    }
    for (int i = start; i <= n - presum; i++)
    {
        datas.emplace_back(i);
        TraceBack(u + 1, i, presum + i,n);
        datas.pop_back();
    }
}
int main()
{
    int n;
    cin >> n;
    TraceBack(0, 0, 0, n);
    for (int i = 0; i < ans.size(); i++)
    {
        int target;
        for (int j = 0; j < ans[i].size(); j++)
        {
            if (ans[i][j] != 0)
            {
                target = j;
                break;
            }
        }
        if (target != 0)
        {
            ans[i].erase(ans[i].begin(), ans[i].begin() + target);
        }
    }
    sort(ans.begin(), ans.end(),cmp);
    for (int i = 0; i < ans.size() - 1; i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            if (ans[i][j] == 0)
            {
                continue;
            }
            cout << ans[i][j];
            if (j + 1 != ans[i].size())
            {
                cout << "+";
            }
        }
        cout << endl;
    }
    return 0;
}