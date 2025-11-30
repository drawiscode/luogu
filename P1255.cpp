#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>>ans;
void Sum(int i)
{
    ans[i].resize(ans[i-1].size()+1);
    for (int j = 0; j < ans[i - 2].size(); j++)
    {
        ans[i][j] += ans[i - 1][j] + ans[i - 2][j];
    }
    for (int j = 0; j < ans[i].size(); j++)
    {
        if (ans[i][j] >= 10)
        {
            ans[i][j + 1] += ans[i][j] / 10;
            ans[i][j] = ans[i][j] % 10;
        }
    }
}
void Print(int u)
{
    int i = ans[u].size() - 1;
    while (ans[u][i] == 0)
    {
        i--;
    }
    for (; i >= 0; i--)
    {
        cout << ans[u][i];
    }
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    ans.resize(n + 1);
    ans[1].emplace_back(1);
    ans[2].emplace_back(2);
    for (int i = 3; i <= n; i++)
    {
        Sum(i);
    }
    Print(n);

    return 0;
}