#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int main()
{
    int n, sourse, target, v0;
    cin >> n >> sourse >> target >> v0;
    vector<int>v(n);
    vector<int>t(n);
    for (int i = 0; i < n; i++)
    {
        cin >> t[i] >> v[i];
    }

    double walk_time = (double)(target - sourse) / (double)v0;
    vector<double>results(n);
    double min_time = walk_time;
    for (int i = 0; i < n; i++)
    {
        results[i] = t[i] + ((double)target / (double)v[i]);
        min_time = min(min_time, results[i]);
    }
    cout << fixed << setprecision(5) << min_time;
    return 0;
}