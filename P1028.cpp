#include <iostream>
#include <vector>
using namespace std;
vector<int>ans;
int main()
{
    int n;
    cin >> n;
    ans.resize(n + 1, 0);
    ans[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int next_sum = i / 2;
        for (int j = 1; j <= next_sum; j++)
        {
            ans[i] += ans[j];
        }
        ans[i] += 1;
    }
    cout << ans[n];
    return 0;
}