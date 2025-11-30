#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode
{
    int parent;
    vector<int>childrens;
};
vector<vector<int>>graphs;
vector<TreeNode>graph;
void BFS(int s)
{
    queue<int>q;
    q.push(s);
    vector<bool>visit(graphs.size(),false);
    while(q.empty()==false)
    {
        int node=q.front();
        for(int i=0;i<graphs.size();i++)
        {
            int v=graphs[node][i];
            if(visit[v]==false)
            {
                visit[v]=true;
                q.push(v);
                graph[v].parent=node;
                graph[node].childrens.emplace_back(v);
            }
        }
    }
}
int Same_Parent(int u,int v)
{
    vector<int>u_parents;
    u_parents.emplace_back(u);
    int u_parent=graph[u].parent;
    while(u_parent!=0)
    {
        u_parents.emplace_back(u_parent);
        u_parent=graph[u_parent].parent;
    }
    while(1)
    {
        
    }
}
int main()
{
    int n,m,s;
    cin>>n>>m>>s;
    graph.resize(n+1);
    graphs.resize(n+1);
    graph[s].parent=0;
    for(int i=0;i<n-1;i++)
    {
        int u;
        int v;
        cin>>u>>v;
        graphs[u].emplace_back(v);
        graphs[v].emplace_back(u);
    }
    vector<pair<int,int>>queries(m);
    for(int i=0;i<m;i++)
    {
        cin>>queries[i].first>>queries[i].second;
    }
    //得到树   
    BFS(s);

    for(int i=0;i<m;i++)
    {
        int u=queries[i].first;
        int v=queries[i].second;
        cout<<Same_Parent(u,v);
    }
    return 0;
}