#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int>heights;
int main()
{
    int n;
    cin >> n;
    heights.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }
    vector<int>left_max(n);
    vector<int>right_max(n);
    left_max[0] = 0;
    right_max[n - 1] = 0;
    for (int i = 1; i < n; i++)
    {
        left_max[i] = max(left_max[i - 1], heights[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        right_max[i] = max(right_max[i + 1], heights[i + 1]);
    }
    long long int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int height = min(right_max[i], left_max[i]);
        if (height > heights[i])
        {
            ans += height - heights[i];
        }
    }
    cout << ans;
    return 0;
}
/*
14
98 43 98 4 98 54 98 4 76 4 87 9 9 58







*/