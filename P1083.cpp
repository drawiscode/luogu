#include <vector>
#include <iostream>
#include <tuple>
using namespace std;
vector<tuple<int, int, int>>queres;
vector<int>days;
bool Can_Fit(int point)
{
    int n = days.size() - 1;
    vector<long long int>diff(n + 2, 0);
    for (int i = 1; i <= point; i++)
    {
        int count = get<0>(queres[i]);
        int left = get<1>(queres[i]);
        int right = get<2>(queres[i]);
        diff[left] += count;
        diff[right + 1] -= count;
    }
    vector<long long int>needs(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        needs[i] = diff[i] + needs[i - 1];
        if (needs[i] > days[i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n, m;
    cin >> n >> m;
    queres.resize(m + 1);
    days.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &days[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        int count;
        int start;
        int end;
        scanf("%d%d%d", &count, &start, &end);
        queres[i]=make_tuple(count, start, end);
    }
    int left = 1;
    int right = m;
    int ans = m + 1;
    while (left <= right)
    {
        int point = (left + right) / 2;
        if (!Can_Fit(point))
        {
            ans = min(ans, point);
            right = point - 1;
        }
        else
        {
            left = point + 1;
        }
    }
    if (ans == m + 1)
    {
        cout << 0;
        return 0;
    }
    cout << -1 << endl << ans;
    return 0;
}