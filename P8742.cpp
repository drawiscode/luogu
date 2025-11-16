#include <iostream>
#include <vector>
using namespace std;
vector<int>weight;
int main()
{
    int n;
    cin >> n;
    weight.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> weight[i];
    }
    vector<vector<bool>>ans(n + 1, vector<bool>(100001, false));
    for (int i = 0; i <= n; i++)
    {
        ans[i][0] = true;
    }
    vector<bool>counts(100001, false);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 100000; j++)
        {
        
            ans[i][j] = ans[i][j] || ans[i - 1][j];
            if (j + weight[i] <= 100000)
            {
                ans[i][j] = ans[i][j] || ans[i - 1][j + weight[i]];
                counts[j] = counts[j] || ans[i - 1][j + weight[i]];
            }
            if (j > weight[i])
            {
                ans[i][j] = ans[i][j]||ans[i - 1][j - weight[i]];
                counts[j] = counts[j] || ans[i - 1][j - weight[i]];
            }
            else if (j <= weight[i])
            {
                ans[i][j] = ans[i][j]||ans[i - 1][weight[i] - j];
                counts[j] = counts[j] || ans[i - 1][weight[i] - j];
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= 100000; i++)
    {
        if (counts[i] == true)
        {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}