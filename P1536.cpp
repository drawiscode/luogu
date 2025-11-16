#include <vector>
#include <iostream>
using namespace std;
void DFS(int u,vector<bool>&visit,vector<vector<int>>&graph)
{
    visit[u]=true;
    for(int i=0;i<graph[u].size();i++)
    {
        int v=graph[u][i];
        if(visit[v]==false)
        {
            DFS(v,visit,graph);
        }
    }
}
int main()
{
    int n,m;
    cin>>n;
    vector<int>ans;
    while(n!=0)
    {
        scanf("%d",&m);
        vector<vector<int>>graph(n+1);
        vector<bool>visit(n+1,false);
        for(int i=0;i<m;i++)
        {
            int u;
            int v;
            scanf("%d%d",&u,&v);
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }
        int count=0;
        for(int i=1;i<=n;i++)
        {
            if(visit[i]==false)
            {
                DFS(i,visit,graph);
                count++;
            }
        }
        ans.emplace_back(count-1);
        scanf("%d",&n);
    }
    for(int i=0;i<ans.size();i++)
    {
        printf("%d\n",ans[i]);
    }
    return 0;
}