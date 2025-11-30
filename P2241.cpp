#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    int m;
    cin >> n >> m;
    long long int ans1 = 0;
    long long int ans2 = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            long long int sum = (n - i + 1) * (m - j + 1);
            long long int sum1 = min(n - i + 1, m - j + 1);
            long long int sum2 = sum - sum1;
            ans1 += sum1;
            ans2 += sum2;
        }
    }
    cout << ans1 << " " << ans2;
    return 0;
}