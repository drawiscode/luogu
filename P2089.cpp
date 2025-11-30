#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>>ans;
bool cmp(vector<int>datas1, vector<int>datas2)
{
    for (int i = 0; i < 10; i++)
    {
        if (datas1[i] < datas2[i])
        {
            return true;
        }
        else if (datas1[i] > datas2[i])
        {
            return false;
        }
    }
    return true;
}
void Oper(int n, int i, vector<int>temp)
{
    if (n == 0)
    {
        if (temp.size() == 10)
        {
            ans.emplace_back(temp);
        }
        return;
    }
    if (i > 10)
    {
        return;
    }
    temp.emplace_back(1);
    Oper(n - 1, i + 1, temp);
    temp.pop_back();
    if (n >= 2)
    {
        temp.emplace_back(2);
        Oper(n - 2, i + 1, temp);
        temp.pop_back();
    }
    if (n >= 3)
    {
        temp.emplace_back(3);
        Oper(n - 3, i + 1, temp);
        temp.pop_back();
    }
    return;
}
int main()
{
    int n;
    cin >> n;
    if (n < 10 || n>30)
    {
        cout << 0;
        return 0;
    }
    vector<int>temp;
    Oper(n, 1, temp);
    sort(ans.begin(), ans.end(), cmp);
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}