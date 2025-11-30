#include <iostream>
#include <vector>
#include <cstdint>
#include <queue>

using namespace std;
vector<vector<int>>graph;
int BFS(int s,int t)
{
    int n=graph.size();
    n--;
    queue<int>q;
    vector<int>visit(n+1,false);
    vector<int>counts(n+1,-1);
    q.push(s);
    visit[s]=true;
    counts[s]=0;
    while(q.empty()==false)
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<graph[u].size();i++)
        {
            int v=graph[u][i];
            if(visit[v]==false)
            {
                visit[v]=true;
                q.push(v);
                counts[v]=counts[u]+1;
            }
        }
    }
    if(counts[t]==-1)
    {
        return -1;
    }
    else
    {
        return counts[t];
    }
}
int main()
{
    int n;
    int s,t;
    cin>>n>>s>>t;
    graph.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        int node;
        cin>>node;
        if(i-node>=1)
        {
            graph[i].emplace_back(i-node);
        }
        if(i+node<=n)
        {
            graph[i].emplace_back(i+node);
        }
    }
    cout<<BFS(s,t);
    return 0;
}