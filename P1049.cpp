#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>>ans;
vector<int>items;
int main()
{
    int V;
    cin >> V;
    int n;
    cin >> n;
    ans.resize(n + 1, vector<int>(V + 1, 0));
    items.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> items[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=V; j++)
        {
            if (j - items[i] >= 0)
            {
                ans[i][j] = max(ans[i - 1][j - items[i]] + items[i], ans[i - 1][j]);
            }
            else
            {
                ans[i][j] = ans[i - 1][j];
            }
        }
    }
    cout << V - ans[n][V];
    return 0;
}