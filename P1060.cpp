#include <iostream>
#include <vector>
using namespace std;
vector<int>prices;
vector<int>importance;
vector<vector<int>>ans;
int main()
{
    int n;
    int m;
    cin >> n >> m;
    prices.resize(m + 1, 0);
    importance.resize(m + 1, 0);
    ans.resize(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
    {
        cin >> prices[i] >> importance[i];
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j >= prices[i])
            {
                ans[i][j] = max(ans[i - 1][j - prices[i]] + prices[i] * importance[i], ans[i - 1][j]);
            }
            else
            {
                ans[i][j] = ans[i - 1][j];
            }
        }
    }
    cout << ans[m][n];
    return 0;
}