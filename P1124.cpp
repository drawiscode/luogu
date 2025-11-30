#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    string num1;
    string num2;
    cin >> num1 >> num2;
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    int k = max(num1.size(), num2.size());
    vector<int>ans(k + 1, 0);
    for (int i = 0; i < k; i++)
    {
        int n1;
        int n2;
        if (num1.size() > i)
        {
            n1 = num1[i] - '0';
        }
        else
        {
            n1 = 0;
        }
        if (num2.size() > i)
        {
            n2 = num2[i] - '0';
        }
        else
        {
            n2 = 0;
        }
        ans[i] = n1 + n2;
    }
    for (int i = 0; i < k; i++)
    {
        if (ans[i] >= 10)
        {
            ans[i + 1] += 1;
            ans[i] -= 10;
        }
    }
    if (ans[k] != 0)
    {
        printf("%d", ans[k]);
    }
    for (int i = k - 1; i >= 0; i--)
    {
        printf("%d", ans[i]);
    }
    return 0;
}