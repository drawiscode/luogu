#include <vector>
#include <iostream>
using namespace std;
vector<vector<vector<int>>>ans;
long long int w(long long int a, long long int b, long long int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }
    else if (a > 20 || b > 20 || c > 20)
    {
        return w(20, 20, 20);
    }
    else if (a < b && b < c)
    {
        return ans[a][b][c - 1] + ans[a][b - 1][c - 1] - ans[a][b - 1][c];
    }
    else
    {
        return ans[a - 1][b][c] + ans[a - 1][b - 1][c] + ans[a - 1][b][c - 1] - ans[a - 1][b - 1][c - 1];
    }
}
int main()
{
    ans.resize(21, vector<vector<int>>(21, vector<int>(21, 1)));
    for (int i = 1; i <= 20; i++)
    {
        for (int j = 1; j <= 20; j++)
        {
            for (int k = 1; k <= 20; k++)
            {
                if (i < j && j < k)
                {
                    ans[i][j][k]= ans[i][j][k - 1] + ans[i][j - 1][k - 1] - ans[i][j - 1][k];
                }
                else
                {
                    ans[i][j][k]=ans[i - 1][j][k] + ans[i - 1][j - 1][k] + ans[i - 1][j][k - 1] - ans[i - 1][j - 1][k - 1];
                }
            }
        }
    }
    long long int a;
    long long int b;
    long long int c;
    cin >> a >> b >> c;
    while (!((a == -1) && (b == -1) && (c == -1)))
    {
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
        cin >> a >> b >> c;
    }
    return 0;
}
/*
2147483648 1 1
-1 -1 -1

*/