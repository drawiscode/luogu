#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    vector<int>weights(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> weights[i];
    }
    vector<bool>ans(m + 1, false);
    ans[0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >=weights[i]; j--)
        {
            ans[j] = ans[j] || ans[j - weights[i]];
        }
    }
    for (int i = m; i >= 0; i--)
    {
        if (ans[i])
        {
            cout << i;
            return 0;
        }
    }
}