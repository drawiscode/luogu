#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct Node
{
    int arrive_time;
    vector<int>persons;
    Node(int time, vector<int>p) :arrive_time(time), persons(p) {}
};
void update_map(unordered_map<int, int>& mp, int &next_delete_num, int curtime, vector<Node>& nodes)
{
    while (curtime >= nodes[next_delete_num].arrive_time + 86400)
    {
        for (int i = 0; i < nodes[next_delete_num].persons.size(); i++)
        {
            mp[nodes[next_delete_num].persons[i]]--;
            if (mp[nodes[next_delete_num].persons[i]] == 0)
            {
                mp.erase(nodes[next_delete_num].persons[i]);
            }
        }
        next_delete_num++;
    }
    return;
}
int main()
{
    int n;
    cin >> n;
    vector<Node>nodes;
    for (int i = 0; i < n; i++)
    {
        int arrive_time;
        int m;
        scanf("%d%d", &arrive_time, &m);
        vector<int>cur(m);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &cur[j]);
        }
        Node node(arrive_time, cur);
        nodes.emplace_back(node);
    }


    unordered_map<int, int>mp;
    int next_delete_num = 0;
    vector<int>ans;
    for (int i = 0; i < n; i++)
    {
        update_map(mp, next_delete_num, nodes[i].arrive_time, nodes);

        for (int j = 0; j < nodes[i].persons.size(); j++)
        {
            int person = nodes[i].persons[j];
            mp[person]++;
        }
        ans.emplace_back(mp.size());
    }


    for (int i = 0; i < ans.size(); i++)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}