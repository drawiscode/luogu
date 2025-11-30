#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>length;
int main()
{
    int n;
    int k;
    cin >> n >> k;
    length.resize(n);
    long long int sumlen = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> length[i];
        sumlen += length[i];
    }
    int l = 0;
    int left = 1;
    int right = (sumlen) / k;
    while (left <= right)
    {
        int point = (left + right) / 2;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += length[i] / point;
        }
        if (sum >= k)
        {
            if (l < point)
            {
                l = point;
            }
            left = point + 1;
        }
        else if (sum < k)
        {
            right = point - 1;
        }
    }
    cout << l;
    return 0;
}