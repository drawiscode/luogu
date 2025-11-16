#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<long long int>ans(n + 1, 0);
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    else if (n == 2)
    {
        cout << 2;
        return 0;
    }
    else if (n == 3)
    {
        cout << 4;
        return 0;
    }
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 4;
    for (int i = 4; i <= n; i++)
    {
        ans[i] = ans[i - 1] + ans[i - 2] + ans[i - 3];
    }
    cout << ans[n];
    return 0;
}