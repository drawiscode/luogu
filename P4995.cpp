#include <iostream>
#include <vector>
#include <cmath>/*8 8 3 4 5 2 1 7 21*/
using namespace std;
long long int Jump(vector<int>& height, int& pre)
{
    int n = height.size();
    int max = 0;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (height[i] != -1)
        {
            if (abs(height[i] - pre) > max)
            {
                max = abs(height[i] - pre);
                
                index = i;
            }
        }
    }
    pre = height[index];
    height[index] = -1;
    return max * max;
}
int main()
{
    int n;
    cin >> n;
    vector<int>height(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &height[i]);
    }
    int pre = 0;
    long long int ans = 0;
    for (int i = 0; i < n; i++)
    {
         ans += Jump(height, pre);
    }
    cout << ans;
    return 0;
}