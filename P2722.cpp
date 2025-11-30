#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t, n;
    cin >> t >> n;
    vector<int>times(n + 1, 0);
    vector<int>scores(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> scores[i] >> times[i];
    }
    vector<int>ans(t + 1, 0);
    int ans1 = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= t; j++)
        {
            int count = 0;
            while (j - times[i] * count >= 0)
            {
                ans[j] = max(ans[j], ans[j - count * times[i]] + scores[i] * count);
                count++;
            }
            ans1 = max(ans1, ans[j]);
        }
    }
    cout << ans1;
    return 0;
}