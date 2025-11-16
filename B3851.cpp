#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <numeric>
using namespace std;
struct Node
{
    int val;
    int count;
    Node() :count(0) {}
};
bool cmp(Node n1, Node n2)
{
    if (n1.count == n2.count)
    {
        if (n1.val < n2.val)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return n1.count > n2.count;
}
int Change(char c1)
{
    if (c1 == 'F')
    {
        return 15;
    }
    else if (c1 == 'E')
    {
        return 14;
    }
    else if (c1 == 'D')
    {
        return 13;
    }
    else if (c1 == 'C')
    {
        return 12;
    }
    else if (c1 == 'B')
    {
        return 11;
    }
    else if (c1 == 'A')
    {
        return 10;
    }
    else
    {
        int ans = c1 - '0';
        return ans;
    }
}
char Change1(int num)
{
    if (num == 10)
    {
        return 'A';
    }
    else if (num == 11)
    {
        return 'B';
    }
    else if (num == 12)
    {
        return 'C';
    }
    else if (num == 13)
    {
        return 'D';
    }
    else if (num == 14)
    {
        return 'E';
    }
    else if (num == 15)
    {
        return 'F';
    }
    else
    {
        return num + '0';
    }
}
vector<Node>colors;
int main()
{
    int n;
    cin >> n;
    colors.resize(256);
    for (int i = 0; i < 256; i++)
    {
        colors[i].val = i;
    }

    vector<string>datas;
    for (int i = 0; i < n; i++)
    {
        string data1;
        cin >> data1;
        datas.emplace_back(data1);

        int index = 0;
        while (index < data1.size())
        {
            int firstnum = Change(data1[index]);
            int secondnum = Change(data1[index + 1]);
            colors[firstnum * 16 + secondnum].count++;
            index = index + 2;
        }
    }
    sort(colors.begin(), colors.end(), cmp);
    vector<int>results;
    for (int i = 0; i < 16; i++)
    {
        results.emplace_back(colors[i].val);
    }

    unordered_map<int, int>mp;
    for (int i = 0; i < 256; i++)
    {
        int mindiff = 256;
        int target;
        for (int j = 0; j < 16; j++)
        {
            if (mindiff > abs(results[j] - i))
            {
                mindiff = abs(results[j] - i);
                target = j;
            }
        }
        mp[i] = target;
    }
    for(int i=0;i<16;i++)
    {
        int num1 = results[i] / 16;
        int num2 = results[i] % 16;

        cout << Change1(num1)<<Change1(num2);
    }
    cout << endl;

    for (int i = 0; i < datas.size(); i++)
    {
        int index = 0;
        while (index < datas[i].size())
        {
            int firstnum = Change(datas[i][index]);
            int secondnum = Change(datas[i][index + 1]);
            int num = firstnum * 16 + secondnum;
            num = mp[num];

            cout << Change1(num);
            index += 2;
        }
        cout << endl;
    }
    return 0;
}