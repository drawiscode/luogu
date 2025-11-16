#include <vector>
#include <iostream>
using namespace std;
vector<vector<long long int>>ans;
vector<int>a;
vector<int>limits;
long long int Oper(int left, int right)
{
    int n = limits.size() - 1;
    ans.assign(n + 1, vector<long long int>(right + 1, 0));

    ans[0][0]=1;
    for (int i = 1; i <= n; i++)
    {
        if (limits[i]!=-1)
        {
            break;
        }
        ans[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= right; j++)
        {
            if (limits[i] == -1)
            {
                int index = 0;
                while (1)
                {
                    if (j - index * a[i] >= 0)
                    {
                        ans[i][j] =((ans[i][j] % 998244353) + (ans[i - 1][j - index * a[i]] % 998244353)) % 998244353;
                    }
                    else
                    {
                        break;
                    }
                    index++;
                }
            }
            else
            {
                if (j - limits[i] * a[i] >= 0)
                {
                    ans[i][j] = ans[i - 1][j - limits[i] * a[i]] % 998244353;
                }
            }

           
        }
    }
    long long int count = 0;
    for (int i = left; i <= right; i++)
    {
        count =(count % 998244353 + ans[n][i] % 998244353) % 998244353;
    }
    return count;
}
int main()
{
    int n, q;
    cin >> n >> q;
    a.resize(n + 1);
    limits.resize(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < q; i++)
    {
        int left, right, k;
        scanf("%d%d%d", &left, &right, &k);
        for (int j = 0; j < k; j++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            limits[x] = y;
        }
        long long int ans = Oper(left, right) % 998244353;
        cout << ans << endl;

        limits.assign(n + 1, -1);
    }
    return 0;
}

/*


4 3
1 10 2 5
10 10 1
3 0
900 910 1
4 2
0 1000 2
2 1
1 5
*/