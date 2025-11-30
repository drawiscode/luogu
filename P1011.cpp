#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int a;
    int n;
    int m;
    int x;
    cin >> a >> n >> m >> x;
    vector<int>up(n + 1, 0);
    vector<int>down(n + 1, 0);
    vector<int>ans(n + 1, 0);
    int cur = 1;
    while (1)
    {
        for (int i = 1; i <= n - 1; i++)
        {
            if (i == 1)
            {
                up[i] = a;
                down[i] = 0;
                ans[i] = a;
            }
            else if (i == 2)
            {
                up[i] = cur;
                down[i] = cur;
                ans[i] = a;
            }
            else
            {
                up[i] = up[i - 1] + up[i - 2];
                down[i] = up[i - 1];
                ans[i] = ans[i - 1] + up[i] - down[i];
            }
        }
        if (ans[n - 1] == m)
        {
            break;
        }
        cur++; 
    }
    cout << ans[x];
    return 0;
}