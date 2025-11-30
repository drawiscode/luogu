#include <vector>
#include <iostream>

using namespace std;
void DFS(vector<vector<int>>&graph,vector<bool>&visit,vector<int>&maxnum,int start,int curnode)
{
    visit[curnode]=true;
    for(int i=0;i<graph[curnode].size();i++)
    {
        int v=graph[curnode][i];
        if(visit[v]==false)
        {
            DFS(graph,visit,maxnum,start,v);
            maxnum[v]=curnode;
        }
    }
}
int main()
{
    int n;
    int m;
    cin>>n>>m;
    vector<vector<int>>graph(n+1);
    for(int i=0;i<m;i++)
    {
        int u;
        int v;
        scanf("%d%d",&u,&v);
        graph[v].emplace_back(u);
    }
    vector<int>maxnum(n+1);
    for(int i=1;i<=n;i++)
    {
        maxnum[i]=i;
    }

    vector<bool>visit(n+1,false);    
    for(int i=n;i>=1;i--)
    {
        DFS(graph,visit,maxnum,i,i);
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d ",maxnum[i]);
    }
    return 0;  
}