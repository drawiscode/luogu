#include<iostream>
#include <vector>
using namespace std;
vector<vector<int>>graph;
vector<bool>visit;
vector<int>ans;
int DFS(int u)
{
    if(graph[u].size()==0)
    {
        ans[u]=1;
        return 1;
    }
    for(int j=0;j<graph[u].size();j++)
    {
        int v=graph[u][j];
        if(visit[v]==false)
        {
            ans[u]=max(ans[u], DFS(v)+1);
        }
    }
}

int main()
{
    int n;
    int m;
    cin>>n>>m;
    graph.resize(n+1);
    visit.resize(n+1,false);
    ans.resize(n+1,0);
    for(int i=0;i<m;i++)
    {
        int u;
        int v;
        cin>>u>>v;
        graph[v].emplace_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        if(graph[i].size()==0)
        {
            ans[i]=1;
        }
        else if(visit[i]==false)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                int v=graph[i][j];
                if(visit[v]==false)
                {
                    ans[i]=max(DFS(v)+1,ans[i]);
                }
                else//true
                {
                    ans[i]=max(ans[v]+1,ans[i]);
                }
            }
        }
    }
    return 0;
}