#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>bili;
vector<vector<int>>ans;
vector<bool>visit;
vector<int>temp;
bool Judge(vector<int>& temp, vector<int>& temps)
{
    int data1 = temp[0] * 100 + temp[1] * 10 + temp[2];
    int data2 = temp[3] * 100 + temp[4] * 10 + temp[5];
    int data3 = temp[6] * 100 + temp[7] * 10 + temp[8];
    temps.emplace_back(data1);
    temps.emplace_back(data2);
    temps.emplace_back(data3);
    //sort(temps.begin(),temps.end(),less<int>());
    if ((temps[0] * bili[1] == temps[1] * bili[0]) && (temps[1] * bili[2] == temps[2] * bili[1]))
    {
        return true;
    }
    return false;
}
void traceback()
{
    if (temp.size() == 9)
    {
        vector<int>temps;
        if (Judge(temp, temps))
        {
            ans.emplace_back(temps);
        }
        return;
    }
    for (int i = 1; i <= 9; i++)
    {
        if (visit[i] == false)
        {
            visit[i] = true;
            temp.emplace_back(i);
            traceback();
            visit[i] = false;
            temp.pop_back();
        }
    }
}

int main()
{
    for (int i = 0; i < 3; i++)
    {
        int node;
        cin >> node;
        if (node == 0)
        {
            cout << "No!!!";
            return 0;
        }
        bili.emplace_back(node);
    }
    sort(bili.begin(), bili.end(), less<int>());
    visit.resize(10, false);
    traceback();
    if (ans.size() == 0)
    {
        cout << "No!!!";
        return 0;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j]<<" ";
        }
        cout << endl;
    }
    return 0;
}