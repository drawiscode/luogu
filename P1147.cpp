#include <iostream>
#include <vector>
using namespace std;
vector<long long int>ans;
int Find(long long int target,int i)
{
    int left = i+1;
    int right = ans.size() - 1;
    while (left <= right)
    {
        int point = (left + right) / 2;
        if (ans[point] == target)
        {
            return point;
        }
        else if (ans[point] < target)
        {
            left = point + 1;
        }
        else
        {
            right = point - 1;
        }
    }
    return -1;
}
int main()
{
    int N;
    cin >> N;
    ans.resize(N+1,-1);
    ans[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        ans[i] = ans[i - 1] + i;
    }
    for (int i = 1; i < N; i++)
    {
        long long int target = ans[i] + N;
        int j = Find(target,i);
        if (j == -1||i+1==j)
        {
            continue;
        }
        printf("%d %d\n", i + 1, j);
    }
    return 0;
}