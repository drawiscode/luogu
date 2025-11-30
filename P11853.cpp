#include <iostream>
#include <vector>
using namespace std;
vector<int>waters;
vector<int>different;
int main()
{
    int n;
    cin >> n;
    waters.resize(1000001);
    different.resize(1000002, 0);
    for (int i = 0; i < n; i++)
    {
        int left;
        int right;
        cin >> left >> right;
        different[left] += 1;
        different[right + 1] -= 1;
    }
    int maxans = different[0];
    for (int i = 1; i <= 1000000; i++)
    {
        different[i] += different[i - 1];
        if (different[i] > maxans)
        {
            maxans = different[i];
        }
    }
    cout << maxans;
    return 0;
}