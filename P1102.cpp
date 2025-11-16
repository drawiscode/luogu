#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node
{
    int val;
    long long int num;
    Node(int v1, int n1) :val(v1), num(n1) {}
};
long long int Find(vector<Node>& nodes, int c)
{
    long long int ans = 0;
    for (int i = 0; i < nodes.size(); i++)
    {
        //A-B=C  ->  B=A-C
        int A = nodes[i].val;
        int B = A - c;

        //找B
        int left = 0;
        int right = nodes.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (B == nodes[mid].val)
            {
                ans += nodes[i].num * nodes[mid].num;
                break;
            }
            else if (B < nodes[mid].val)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
    }
    return ans;
}
int main()
{
    int n;
    int c;
    cin >> n >> c;
    vector<int>data(n);
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &data[i]);
    }
    sort(data.begin(), data.end(), less<int>());

    vector<Node>nodes;
    int pre = data[0];
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (data[i] != pre)
        {
            Node n1(pre, count);
            nodes.emplace_back(n1);
            //
            count = 1;
            if (i == n - 1)
            {
                Node n1(data[i], count);
                nodes.emplace_back(n1);
                break;
            }
        }
        else
        {
            count++;
            if (i == n - 1)
            {
                Node n1(pre, count);
                nodes.emplace_back(n1);
                break;
            }
        }
        pre = data[i];
    }

    long long int ans = Find(nodes, c);
    cout << ans << endl;
    return 0;
}