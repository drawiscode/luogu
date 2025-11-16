#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>attacks;
struct Node
{
    int index;
    int val;
};
bool cmp(Node n1, Node n2)
{
    return n1.val < n2.val;
}
int Oper(int point, int m) //0 1 2
{
    int n = attacks.size();
    int blood_me = m;
    int blood_enermy = m;
    for (int i = 0; i < n; i++)
    {
        if (attacks[i] > 0)
        {
            blood_enermy -= point + attacks[i];
            if (blood_enermy <= 0)
            {
                return 1;
            }
        }
        else
        {
            blood_me += attacks[i];
            if (blood_me <= 0)
            {
                return 0;
            }
        }
    }
    return 2;
}
int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<Node>tools(q);
    attacks.resize(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &attacks[i]);
    }
    for (int i = 0; i < q; i++)
    {
        scanf("%d",&tools[i].val);
        tools[i].index = i;
    }
    sort(tools.begin(), tools.end(),cmp);
    int left = 0;
    int right = q - 1;
    vector<int>results(q);
    while (left <= right)
    {
        int point = (left + right) / 2;
        int result = Oper(tools[point].val, m);
        if (result == 0)
        {
            for (int i = left; i <= point; i++)
            {
                int index = tools[i].index;
                results[index] = 0;
            }
            left = point + 1;
        }
        else if (result == 1)
        {
            for (int i = point; i <= right; i++)
            {
                int index = tools[i].index;
                results[index] = 1;
            }
            right = point - 1;
        }
        else
        {
            for (int i = left; i <= point; i++)
            {
                int index = tools[i].index;
                results[index] = 2;
            }
            left = point + 1;
        }
    }
    for (int i = 0; i < q; i++)
    {
        if (results[i] == 0)
        {
            printf("No\n");
        }
        else if (results[i] == 1)
        {
            printf("Yes\n");
        }
        else
        {
            printf("Tie\n");
        }
    }
    return 0;
}