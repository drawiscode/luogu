#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;
vector<int>schools;
vector<int>students;
int main()
{
    int m;
    int n;
    cin >> m >> n;
    schools.resize(m);
    students.resize(n);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &schools[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &students[i]);
    }
    sort(schools.begin(), schools.end(), less<int>());
    long long int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int left = 0;
        int right = m - 1;
        int point;
        while (left <= right)
        {
            point = (left + right) / 2;
            if (schools[point] < students[i])
            {
                left = point + 1;
            }
            else
            {
                right = point - 1;
            }
        }
        int add = abs(students[i] - schools[point]);
        if (point + 1 < schools.size())
        {
            add = min(add, abs(students[i] - schools[point + 1]));
        }
        if (point - 1 >= 0)
        {
            add = min(add, abs(students[i] - schools[point - 1]));
        }
        sum += add;
    }
    cout << sum;
    return 0;
}