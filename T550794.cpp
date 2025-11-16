#include <iostream>
#include <vector>
using namespace std;
vector<int>limits;
vector<int>a;
long long int TraceBack(int& left, int& right, int i, int sum)
{
    int n = limits.size();
    n--;
    if (i == n)
    {
        if (limits[n] != -1)
        {
            if (sum >= left && sum <= right)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            int index = 0;
            if (sum < left)
            {
                int add = left - sum;
                int addcount;
                if (add % a[n] == 0)
                {
                    addcount = add / a[n];
                }
                else
                {
                    addcount = (add / a[n]) + 1;
                }

                sum += addcount * a[n];
            }
            int count = 0;
            while (sum <= right)
            {
                count++;
                sum += a[i];
            }
            return count % 998244353;
        }
    }
    else
    {
        if (limits[i] != -1)//这个元素被限制了
        {
            return TraceBack(left, right, i + 1, sum) % 998244353;
        }
        else//没有被限制
        {
            int index = 0;
            long long int count = 0;
            while (sum + index * a[i] <= right)
            {
                count = (count % 998244353) + (TraceBack(left, right, i + 1, sum + index * a[i]) % 998244353);
                index++;
            }
            return count % 998244353;
        }
    }
}
int main()
{
    int n, q;
    cin >> n >> q;
    limits.resize(n + 1, -1);
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < q; i++)
    {
        int left, right, limit;
        scanf("%d%d%d", &left, &right, &limit);
        int sum = 0;
        for (int j = 0; j < limit; j++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            limits[x] = y;
            sum = sum + limits[x] * a[x];
        }
        long long int ans = TraceBack(left, right, 1, sum) % 998244353;
        cout << ans << endl;
        limits.assign(n + 1, -1);
    }

    return 0;
}

/*
4 1
1 10 2 5
900 910 1
4 2
*/