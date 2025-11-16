#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int>dists;
vector<vector<pair<int,int>>>graph;

void DFS(int u,vector<bool>&visit)
{
    visit[u]=true;
    for(int i=0;i<graph[u].size();i++)
    {
        int v=graph[u][i].first;
        if(visit[v]==false)
        {
            DFS(v,visit);
        }
    }
}
int main()
{
    int n;
    int m;
    cin>>n>>m;
    graph.resize(n+1);
    for(int i=0;i<m;i++)
    {
        int u;
        int v;
        int val;
        scanf("%d%d%d",&u,&v,&val);
        graph[u].emplace_back(make_pair(v,val));
        graph[v].emplace_back(make_pair(u,val));
    }

    //判断图是否连通
    vector<bool>visit(n+1,false);
    int count=0;
    for(int i=1;i<=n;i++)
    {
        if(visit[i]==false)
        {
            DFS(i,visit);
            count++;
        }        
    }
    if(count!=1)
    {
        cout<<"orz";
        return 0;
    }

    //求最小生成树
    int ans=0;
    dists.resize(n+1,10000001);
    vector<bool>S(n+1,false);
    S[1]=true;
    dists[1]=0;
    int cur=1;
    while(1)
    {
        S[cur]=true;
        for(int i=0;i<graph[cur].size();i++)
        {
            int v=graph[cur][i].first;
            if(S[v]==false)
            {
               dists[v]=min(dists[v],graph[cur][i].second);
            }
        }
        int mindist=1000001;
        for(int i=1;i<=n;i++)
        {
            if(mindist>dists[i]&&S[i]==false)
            {
                mindist=dists[i];
                cur=i;
            }
        }
        if(mindist==1000001)
        {
            break;
        }
        ans+=dists[cur];
    }
    cout<<ans;
    return 0;
}