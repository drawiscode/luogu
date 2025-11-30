#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    else if (n == 2)
    {
        cout << 2;
        return 0;
    }
    vector<pair<double, double>>datas;
    for (int i = 0; i < n; i++)
    {
        double x;
        double y;
        cin >> x >> y;
        datas.emplace_back(make_pair(x,y));
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int count = 2;
            double x1 = datas[i].first;
            double y1 = datas[i].second;
            double x2 = datas[j].first;
            double y2 = datas[j].second;
            for (int k = 0; k != i && k != j; k++)
            {
                double x3 = datas[k].first;
                double y3 = datas[k].second;
                if (x1 == x2)
                {
                    if (x1 == x3)
                    {
                        count++;
                    }
                }
                else if ((y1 - y2) / (x1 - x2) == (y1 - y3) / (x1 - x3))
                {
                    count++;
                }
            }
            ans = max(ans, count);
        }
    }
    cout << ans;
    return 0;
}