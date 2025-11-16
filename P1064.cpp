#include < iostream>
#include <vector>
using namespace std;
struct Node
{
    int prices;
    int sum_of_importance;
    Node() :prices(0), sum_of_importance(0) {}
};
vector<Node>items;
vector<vector<int>>ans;
int main()
{
    int n;
    int m;
    cin >> n >> m;
    Node n1;
    items.emplace_back(n1);
    int count = 0;
    for (int i = 1; i <= m; i++)
    {
        int price;
        int importance;
        int parent;
        cin >> price >> importance >> parent;
        if (parent == 0)
        {
            count++;
            Node node;
            items.emplace_back(node);
            items[count].prices += price;
            items[count].sum_of_importance += price * importance;
        }
        else
        {
            items[parent].prices += price;
            items[parent].sum_of_importance += price * importance;
        }
    }
    ans.resize(count + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= count; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (items[i].prices <= j)
            {
                ans[i][j] = max(ans[i - 1][j - items[i].prices] + items[i].sum_of_importance, ans[i - 1][j]);
            }
            else
            {
                ans[i][j] = ans[i - 1][j];
            }
        }
    }
    cout << ans[count][n];
    return 0;
}