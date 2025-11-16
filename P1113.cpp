#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>>graph;
vector<int>tasks;
queue<int>q;
vector<int>in_degree;
vector<int>start_time;
vector<int>finish_time;

void Oper()
{
    //int count=0;
    while(q.empty()==false)
    {
        int u=q.front();
        q.pop();
        finish_time[u]=start_time[u]+tasks[u];
        for(int i=0;i<graph[u].size();i++)
        {
            int v=graph[u][i];
            start_time[v]=max(start_time[v],finish_time[u]);
            in_degree[v]--;
            if(in_degree[v]==0)
            {
                q.push(v);
            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    
 
    graph.resize(n+1);
    tasks.resize(n+1);
    in_degree.resize(n+1,0);
    start_time.resize(n+1,0);
    finish_time.resize(n+1);

    for(int i=1;i<=n;i++)
    {   
        int u;
        scanf("%d",&u);
        scanf("%d",&tasks[i]);

        int v;
        scanf("%d",&v);
        while(v!=0)
        {
            graph[v].emplace_back(u);
            in_degree[u]++;
            scanf("%d",&v);
        }   
    }

    for(int i=1;i<=n;i++)
    {
        if(in_degree[i]==0)
        {
            q.push(i);
        }
    }
    Oper();

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,finish_time[i]);
    }
    printf("%d",ans);
    return 0;
}