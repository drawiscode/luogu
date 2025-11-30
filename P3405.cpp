#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<pair<string, string>>init_data;
vector<pair<string, string>>sort_data;
bool cmp(pair<string, string>data1, pair<string, string>data2)
{
    string s12 = data1.second;
    string s22 = data2.second;
    if (s12 > s22)
    {
        return false;
    }
    else if (s12 <= s22)
    {
        return true;
    }
}
int Find(int u)
{
    string target = init_data[u].first;
    int left = 0;
    int right = sort_data.size() - 1;
    while (left <= right)
    {
        int point = (left + right) / 2;
        string current = sort_data[point].second;
        if (target == current)
        {
            return 1;
        }
        else if (current > target)
        {
            right = point - 1;
        }
        else
        {
            left = point + 1;
        }
    }
    return 0;
}
int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string s1;
        string s2;
        cin >> s1 >> s2;
        string s3(s1.begin(), s1.begin() + 2);
        init_data.emplace_back(make_pair(s3, s2));
        sort_data.emplace_back(make_pair(s3, s2));
    }
    sort(sort_data.begin(), sort_data.end(), cmp);
    long long int ans = 0;
    for (int i = 0; i < N; i++)
    {
        ans += Find(i);
    }
    cout << ans;
    return 0;
}