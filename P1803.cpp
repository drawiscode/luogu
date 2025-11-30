#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Node
{
    int start;
    int end;
    Node() { start = 0; end = 0; }
    Node(int s,int e):start(s),end(e){}
};
bool cmp(Node n1,Node n2)
{
    return n1.end<n2.end;
}
int main()
{
    int n;
    scanf("%d",&n);
    vector<Node>data(n);
    for(int i=0;i<n;i++)
    {
        int s,e;
        scanf("%d%d",&s,&e);
        data[i].start=s;
        data[i].end=e;
    }
    sort(data.begin(),data.end(),cmp);
    int count=1;
    int time=data[0].end;
    for(int i=1;i<n;i++)
    {
        if(time<=data[i].start)
        {
            time=data[i].end;
            count++;
        }
    }
    printf("%d",count);
    return 0;
}