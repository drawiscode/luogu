#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    cin >> m >> n;
    vector<int>weights(n + 1, 0);
    vector<int>vals(n + 1, 0);
    vector<vector<int>>groups(101);
    for (int i = 1; i <= n; i++)
    {
        cin >> weights[i] >> vals[i];
        int x;
        cin >> x;
        groups[x].emplace_back(i);
    }
    vector<long long int>f(m + 1, 0);
    for (int i = 1; i <= 100; i++)
    {
        if (groups[i].size() == 0)
        {
            continue;
        }
        for (int j = m; j >= 0; j--)
        {
            for (int k = 0; k < groups[i].size(); k++)
            {
                if (j >= weights[groups[i][k]])
                {
                    f[j] = max(f[j], f[j - weights[groups[i][k]]] + vals[groups[i][k]]);
                }
            }
        }
    }
    cout << f[m];
    return 0;
}