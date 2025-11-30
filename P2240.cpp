#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
struct Node
{
    int val;
    int weight;
    double val_per_weight;
    Node(int m,int v):weight(m),val(v){val_per_weight=(double)val/(double)weight;}
};
bool cmp(Node n1,Node n2)
{
    return n1.val_per_weight>n2.val_per_weight;
}
int main()
{
    int N,T;
    scanf("%d%d",&N,&T);
    vector<Node>data;
    for(int i=0;i<N;i++)
    {
        int m;
        int v;
        scanf("%d%d",&m,&v);
        Node node(m,v);
        data.emplace_back(node);
    }
    sort(data.begin(),data.end(),cmp);
    double max_val=0;
    int w=0;
    int i=0;
    while(w<T&&i!=N)
    {
        if(w+data[i].weight<T)
        {
            w+=data[i].weight;
            max_val+=data[i].val;
        }
        else
        {
            max_val += (T-w)*data[i].val_per_weight;
            w = T;
        }
        i++;
    }
    cout << fixed<<setprecision(2)<<max_val;
    return 0;
}