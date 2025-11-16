#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int>prices(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> prices[i];
    }
    vector<int>ans(m + 1, 0);
    ans[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--)
        {
            if (j >= prices[i])
            {
                ans[j] += ans[j - prices[i]];
            }
        }
    }
    cout << ans[m];
    return 0;
}