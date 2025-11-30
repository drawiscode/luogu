#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int>heights(20000001, 0);
    for (int i = 0; i < n; i++)
    {
        int node;
        cin >> node;
        heights[node]++;
    }

    int maxheight = 0;
    for (int i = 20000001; i >= 1; i--)
    {
        if (heights[i] > 0)
        {
            maxheight = i;
            break;
        }
    }
    long long int ans = 0;
    for (int i = 1; i <= maxheight; i++)
    {
        if (heights[i] != 0)
        {
            ans += 5 + heights[i];
        }
        ans += 6;
    }
    ans += maxheight * 4;
    cout << ans;
    return 0;
}