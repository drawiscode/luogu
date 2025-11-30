#include <iostream>
#include <vector>
using namespace std;
vector<int>height;
int main()
{
    int n;
    cin >> n;
    height.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }
    for (int i = 0; i < height.size()-1; i++)
    {
        if (height[i] == height[i + 1])
        {
            height.erase(height.begin() + i + 1);
            i--;
        }
    }
    int count = 0;
    for (int i = 1; i <height.size()-1; i++)
    {
        if (height[i] < height[i - 1] && height[i] < height[i + 1])
        {
            count++;
        }
    }
    cout << count;
    return 0;
}