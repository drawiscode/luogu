#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>heights;
bool Oper(int point, int M)
{
    long long int sum = 0;
    for (int i = point + 1; i < heights.size(); i++)
    {
        sum += heights[i] - heights[point];
    }
    if (M > sum)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int main()
{
    int N;
    long long int M;
    cin >> N >> M;
    heights.resize(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &heights[i]);
    }
    int ans = 0;
    int left = 0;
    int right = N - 1;
    int indexans;
    sort(heights.begin(), heights.end(), less<int>());
    while (left <= right)
    {
        int point = (left + right)/2;
        if (Oper(point, M))
        {
            if (ans < heights[point])
            {
                ans = heights[point];
                indexans = point;
            }
            left = point + 1;
        }
        else
        {
            right = point - 1;
        }
    }
    if (ans == 0)
    {
        int sum = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            sum += heights[i] - heights[0];
        }
        long long int Less_M = M - sum;
        ans = ans - (Less_M) / (heights.size());
        cout << ans;
        return 0;
    }
    long long int sum = 0;
    for (int i = indexans+1; i < heights.size(); i++)
    {
        sum += heights[i]-heights[indexans];
    }//5 10
    long long int More_M = sum - M;
    ans = ans + (More_M)/(heights.size()-indexans-1);
    cout << ans;
    return 0;
}