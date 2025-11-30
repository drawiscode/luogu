#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    int M;
    int T;
    cin >> n >> M >> T;
    vector<int>times(n + 1, 0);
    vector<int>moneys(n + 1, 0);
    vector<vector<long long int>>f(T + 1, vector<long long int>(M + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        cin >> moneys[i] >> times[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = T; j >= times[i]; j--)
        {
            for (int k = M; k >= moneys[i]; k--)
            {
                f[j][k] = max(f[j][k], f[j - times[i]][k - moneys[i]] + 1);
            }
        }
    }
    cout << f[T][M];
    return 0;
}