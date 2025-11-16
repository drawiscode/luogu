#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int val;
    int index;
    Node(int v, int i) :val(v), index(i) {}
};
void Find(vector<Node>& data, vector<int>& queres, vector<int>& ans)
{
    int n = data.size();
    for (int i = 0; i < queres.size(); i++)
    {
        int quere = queres[i];
        int left = 0;
        int right = n - 1;
        ans[i] = -1;
        while (left <= right)
        {
            int mid = (left + right) / 2;

            if (data[mid].val == quere)
            {
                ans[i] = data[i].index;
                break;
            }
            else if (data[mid].val < quere)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }
    return;
}
void Print(vector<int>& ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        printf("%d ", ans[i]);
    }
    return;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<Node>data;
    int pre = -1;
    for (int i = 1; i <= n; i++)
    {
        int node;
        scanf("%d", &node);
        if (node != pre)
        {
            Node n1(node, i);
            data.emplace_back(n1);
        }
        pre=node;
    }
    vector<int>queres(m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &queres[i]);
    }
    vector<int>ans(m);
    Find(data, queres, ans);
    Print(ans);
    return 0;
}