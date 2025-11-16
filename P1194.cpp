#include <iostream>
#include <vector>
using namespace std;
vector<vector<pair<int,int>>>graph;
vector<int>dists;
int main()
{
    int a,n;
    cin>>a>>n;
    graph.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int val;
            cin>>val;
            if(val==0||val>a)
            {
                val=a;
            }
            if(i==j)
            {
                continue;
            }
            graph[i].emplace_back(make_pair(j,val));
        }
    }

    //求最小生成树
    dists.resize(n+1,10000001);
    dists[1]=0;
    int sum=a;
    int cur=1;
    vector<bool>S(n+1,false);
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
        int mindist=10000001;
        for(int i=1;i<=n;i++)
        {
            if(S[i]==false)
            {
                if(mindist>dists[i])
                {
                    mindist=dists[i];
                    cur=i;
                }
            }
        }
        if(mindist==10000001)
        {
            break;
        }
        sum+=dists[cur];
    }
    cout<<sum;
    return 0;
}