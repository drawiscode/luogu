#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
vector<int>partners;
vector<unordered_set<int>>know_birth;
int main()
{
    int n;
    cin >> n;
    partners.resize(n + 1);
    know_birth.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int partner;
        cin >> partner;
        partners[i] = partner;
        know_birth[i].insert(i);
    }
    int count = 0;
    while (1)
    {
        count++;
        vector<vector<int>>information(n+1);
        for (int i = 1; i <= n; i++)
        {
            int partner = partners[i];
            for (auto node : know_birth[i])
            {
                if (know_birth[partner].find(node) == know_birth[partner].end())
                {
                    information[partner].emplace_back(node);
                }
            }
        }
        if (count == 1)
        {
            for (int i = 1; i <= n; i++)
            {
                know_birth[i].erase(i);
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < information[i].size(); j++)
            {
                if (know_birth[i].find(information[i][j]) == know_birth[i].end())
                {
                    know_birth[i].insert(information[i][j]);
                }
            }
            
        }

        bool know = false;
        for (int i = 1; i <= n; i++)
        {
            if (know_birth[i].find(i) != know_birth[i].end())
            {
                know = true;
                break;
            }
        }
        if (know)
        {
            break;
        }
    }
    cout << count;
    return 0;
}