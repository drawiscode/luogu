#include <iostream>
#include <vector>
using namespace std;
vector<int>grades;
vector<int>different;
int main()
{
    int n, p;
    cin >> n >> p;
    grades.resize(n + 1);
    different.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> grades[i];
        if (i != 1)
        {
            different[i] = grades[i] - grades[i - 1];
        }
        else
        {
            different[1] = grades[1];
        }
    }
    for (int i = 0; i < p; i++)
    {
        int left;
        int right;
        int add;
        cin >> left >> right >> add;
        different[left] += add;
        if (right < n)
        {
            different[right + 1] -= add;
        }
    }
    int mingrade = different[1];
    int curgrade = different[1];
    for (int i = 2; i <= n; i++)
    {
        curgrade += different[i];
        if (curgrade < mingrade)
        {
            mingrade = curgrade;
        }
    }
    cout << mingrade;
    return 0;
}