#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>>graph;

void DFS(int u)
{
    ;
}

vector<int>Mul(vector<int>data1, vector<int>data2)
{
    int size1 = data1.size();
    int size2 = data2.size();
    vector<int>results(size1 + size2, 0);
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            results[i + j] += data1[i] * data2[j];
        }
    }
    for (int i = 0; i < results.size(); i++)
    {
        if (results[i] >= 10)
        {
            results[i + 1] += results[i] / 10;
            results[i] = results[i] % 10;
        }
    }
    return results;
}
void Print(vector<int>ans)
{
    int i = ans.size() - 1;
    while (ans[i] == 0)
    {
        i--;
    }
    for (int j = i; j >= 0; j--)
    {
        cout << ans[j];
    }
    cout << endl;
}

int main()
{
    unordered_map<char, vector<char>>mp;
    string n;
    graph.resize(10);
    int k;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        char key;
        char val;
        cin >> key >> val;
        mp[key].emplace_back(val);
    }
    vector<int>ans;
    ans.emplace_back(1);
    for (int i = 0; i < n.size(); i++)
    {
        if (mp.find(n[i]) != mp.end())
        {
            int x= mp[n[i]].size() + 1;
            vector<int>temp;
            while (x != 0)
            {
                temp.emplace_back(x%10);
                x /= 10;
            }

          ///  Print(ans);
           // Print(temp);

            ans=Mul(ans,temp);

        }
    }
    
    int index = ans.size() - 1;
    while (ans[index] == 0)
    {
        index--;
    }
    for (int i = index; i >= 0; i--)
    {
        cout << ans[i];
    }
    return 0;
}
/*
2234 3
2 5
2 6
3 6


1234 3
2 3
3 2
3 5

9
*/