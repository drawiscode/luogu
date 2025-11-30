#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<long long int>datas(n);
    vector<long long int>prefix_sum(n);
    cin >> datas[0];
    for (int i = 1; i < n; i++)
    {
        cin >> datas[i];
        prefix_sum[i] = prefix_sum[i - 1] + datas[i];
    }
    long long int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += datas[i] * (prefix_sum[n - 1] - prefix_sum[i]);
    }
    cout << sum;
    return 0;
}