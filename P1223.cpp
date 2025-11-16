#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
struct Node
{
    int index;
    int time;
    Node(int t, int i) :time(t), index(i + 1) {}
};
bool cmp(Node n1, Node n2)
{
    return n1.time < n2.time;
}
int main()
{
    int n;
    scanf("%d", &n);
    vector<Node>time;
    for (int i = 0; i < n; i++)
    {
        int cur;
        scanf("%d", &cur);
        Node node(cur, i);
        time.emplace_back(node);
    }
    sort(time.begin(), time.end(), cmp);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", time[i].index);
    }
    printf("\n");

    long long int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (n - i -1) * time[i].time;
    }
    cout << fixed << setprecision(2) << (double)sum / n;
    return 0;
}