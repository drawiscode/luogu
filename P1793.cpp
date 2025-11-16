#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>>graph;
vector<int>ans;
void BFS(int u)
{
    int n=graph.size()-1;
    vector<bool>visit(n+1,false);
    visit[u]=true;
    queue<int>q;
    q.push(1);
    visit[1]=true;
    while(q.empty()==false)
    {
        int node=q.front();
        if(node==n)
        {
            return;
        }
        q.pop();
        for(int i=0;i<graph[node].size();i++)
        {
            int v=graph[node][i];
            if(visit[v]==false)
            {
                visit[v]=true;
                q.push(v);
            }
        }
    }
    ans.emplace_back(u);
    return;
}
int main()
{
    int n,m;
    cin>>n>>m;
    graph.resize(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    for(int i=2;i<=n-1;i++)
    {
        BFS(i);
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
/*
6 6
1 2
2 4
2 3
3 5
4 5
5 6

*/