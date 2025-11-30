#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;


unordered_map<string, pair<string, int>>mp;
string str;
string P;
vector<int>ans;

bool cmp(pair<string, int>data1, pair<string, int>data2)
{
    return data1.second < data2.second;
}
void Oper(int index)
{
    string temp = P + str[index];
    if (mp.find(temp) != mp.end())
    {
        P = temp;
        return;
    }
    else
    {
        int sizes = mp.size();
        mp[temp] = make_pair(temp, sizes + 1);
        ans.emplace_back(mp[P].second);
        P = str[index];
    }
}
int main()
{
    int n, k, s;
    cin >> n >> k >> s;
    for (int i = 1; i <= k; i++)
    {
        string key;
        cin >> key;
        mp[key] = make_pair(key, i);
    }
    cin >> str;
    P = "";
    for (int i = 0; i < n; i++)
    {
        Oper(i);
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << mp[P].second;


    cout << endl;
    vector<pair<string, int>>sort_data;
    for (auto node : mp)
    {
        string s1 = node.second.first;
        int key1 = node.second.second;
        sort_data.emplace_back(make_pair(s1, key1));
    }
    cout << mp.size() << endl;
    sort(sort_data.begin(), sort_data.end(), cmp);
    for (int i = 0; i < sort_data.size(); i++)
    {
        cout << sort_data[i].first << endl;
    }
    return 0;
}