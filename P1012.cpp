#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool cmp(string s1, string s2)
{
    if (s1 + s2 > s2 + s1)
    {
        return true;
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    vector<string>num;
    for (int i = 0; i < n; i++)
    {
        string data;
        cin >> data;
        num.emplace_back(data);
    }
    sort(num.begin(), num.end(), cmp);
    string ans;
    for (int i = 0; i < n; i++)
    {
        ans += num[i];
    }
    cout << ans << endl;
    return 0;
}