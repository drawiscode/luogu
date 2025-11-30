#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int index;
    int val;
    Node(int i, int v) :index(i), val(v) {}
    Node(){}
};
int Oper(vector<Node>teams)
{
    if (teams.size() == 2)
    {
        return (teams[0].val > teams[1].val) ? teams[1].index : teams[0].index;
    }
    else
    {
        int n = teams.size();
        
        vector<Node>temp;
        for (int i = 0; i < n; i = i + 2)
        {
            int valtemp;
            int indextemp;
            if (teams[i].val > teams[i + 1].val)
            {
                valtemp = teams[i].val;
                indextemp = teams[i].index;
            }
            else
            {
                valtemp = teams[i + 1].val;
                indextemp = teams[i + 1].index;
            }
            Node node(indextemp, valtemp);
            temp.emplace_back(node);
        }
        return Oper(temp);
    }
}
int main()
{
    int n;
    cin >> n;
    n = 1 << n;
    vector<Node>teams(n);
    for (int i = 0; i < n; i++)
    {
        int v;
        scanf("%d", &v);
        teams[i].index = i+1;
        teams[i].val = v;
    }
    int ans = Oper(teams);
    cout << ans;
    return 0;
}