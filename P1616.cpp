#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t;
    int m;
    cin >> t >> m;
    vector<int>weights(m + 1);
    vector<int>vals(m + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> weights[i] >> vals[i];
    }
    vector<long long int>f(t + 1, 0);
    for (int i = 1; i <= m; i++)
    {
        for (int j = weights[i]; j <= t; j++)
        {
            f[j] = max(f[j], f[j - weights[i]] + vals[i]);
        }
    }
    cout << f[t];
    return 0;
}