#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>vals;
vector<int>times;
int main()
{
    int T;
    int M;
    cin >> T >> M;
    vals.resize(M + 1, 0);
    times.resize(M + 1, 0);
    for (int i = 1; i <= M; i++)
    {
        cin >> times[i] >> vals[i];
    }
    vector<vector<int>>ans(M + 1, vector<int>(T+1, 0));
    for (int i = 1; i <= M; i++)
    {
        for (int j = T; j >= 0; j--)
        {
            if (times[i] <= j)
            {
                ans[i][j] = max(ans[i - 1][j - times[i]] + vals[i], ans[i - 1][j]);
            }
            else
            {
                ans[i][j] = ans[i - 1][j];
            }
        }
    }
    cout << ans[M][T];
    return 0;
}