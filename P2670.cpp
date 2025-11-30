#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<vector<char>>ans;
int Count(vector<string>& data, int i, int j)
{
    int n = data.size();
    int m = data[0].size();
    int count = 0;
    if (i - 1 >= 0 && data[i - 1][j] == '*')
    {
        count++;
    }
    if (i + 1 < n && data[i + 1][j] == '*')
    {
        count++;
    }
    if (j - 1 >= 0 && data[i][j - 1] == '*')
    {
        count++;
    }
    if (j + 1 < n && data[i][j + 1] == '*')
    {
        count++;
    }

    if (i - 1 >= 0 && j - 1 >= 0 && data[i - 1][j - 1] == '*')
    {
        count++;
    }
    if (i + 1 < n && j - 1 >= 0 && data[i + 1][j - 1] == '*')
    {
        count++;
    }
    if (j + 1 >= 0 && i + 1 < n && data[i + 1][j + 1] == '*')
    {
        count++;
    }
    if (j + 1 < n && i - 1 >= 0 && data[i - 1][j + 1] == '*')
    {
        count++;
    }
    return count;
}
void Oper(vector<string>& data)
{
    int n = data.size();
    int m = data[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (data[i][j] == '*')
            {
                ans[i][j] = '*';
                continue;
            }
            char count = '0';
            count += Count(data, i, j);
            ans[i][j] = count;
        }
    }
}
void Print()
{
    int n = ans.size();
    int m = ans[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%c", ans[i][j]);
        }
        printf("\n");
    }
    return;
}
int main()
{
    int n;
    int m;
    cin >> n >> m;
    ans.resize(n, vector<char>(m));
    vector<string>data;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        data.emplace_back(temp);
    }
    Oper(data);
    Print();
    return 0;
}