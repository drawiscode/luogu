#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    int w;
    cin >> n >> w;
    vector<int>a(n);
    vector<int>ans(w + 1, 10001);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] <= w)
        {
            ans[a[i]] = 1;
        }
    }
    sort(a.begin(), a.end(), less<int>());

    for (int i = 1; i <= w; i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            if (i - a[j] > 0)
            {
                ans[i] = min(ans[i - a[j]] + 1, ans[i]);
            }
            else
            {
                break;
            }

        }
    }
    cout << ans[w];
    return 0;
}