#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node
{
    int d;
    vector<int>nbr;
};
int main()
{
    vector<Node>graph;
    int n;
    int d;
    cin>>n>>d;
    graph.resize(n+1);
    for(int i=0;i<n-1;i++)
    {
        int u;
        int v;
        scanf("%d%d",&u,&v);
        graph[u].nbr.emplace_back(v);
        graph[v].nbr.emplace_back(u);
    }
    int count = 0;
    
    queue<Node>q;
    graph[1].d=0;
    q.push(graph[1]);

    vector<bool>visited(n+1,false);
    visited[1]=true;
    while(q.empty()==false)
    {
        Node node = q.front();
        q.pop();
        bool end =false;
        for(auto i:node.nbr)
        {
            if(visited[i]==false)
            {
                if(node.d==d)
                {
                    break;
                }
                visited[i]=true;
                count++;
                graph[i].d = node.d+1;
                q.push(graph[i]);
            }
        }
    }
    printf("%d",count);
    return 0;
}