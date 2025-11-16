#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<bool>>use;
vector<vector<long long int>>counts;
int n;
int m;
bool legal(int x,int y)
{
    if(x<0||y<0||x>n||y>m)
    {
        return false;
    }
    else if(use[x][y]==false)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void Add(int x,int y)
{
    if(legal(x+1,y))
    {
        counts[x][y]+=counts[x+1][y];
    }
    if(legal(x-1,y))
    {
        counts[x][y]+=counts[x-1][y];
    }
    if(legal(x,y+1))
    {
        counts[x][y]+=counts[x][y+1];
    }
    if(legal(x,y-1))
    {
        counts[x][y]+=counts[x][y-1];
    }
}
void BFS(int x,int y)
{
   queue<pair<int,int>>q;
   q.emplace(make_pair(x,y));
   while(q.empty()==false)
   {
        int tempx=q.front().first;
        int tempy=q.front().second;
        q.pop();
        if(legal(tempx+1,tempy)&&counts[tempx+1][tempy]==0)
        {
            Add(tempx+1,tempy);
            q.push(make_pair(tempx+1,tempy));
        }
        if(legal(tempx-1,tempy)&&counts[tempx-1][tempy]==0)
        {
            Add(tempx-1,tempy);
            q.push(make_pair(tempx-1,tempy));
        }
        if(legal(tempx,tempy-1)&&counts[tempx][tempy-1]==0)
        {
            Add(tempx,tempy-1);
            q.push(make_pair(tempx,tempy-1));
        }
        if(legal(tempx,tempy+1)&&counts[tempx][tempy+1]==0)
        {
            Add(tempx,tempy+1);
            q.push(make_pair(tempx,tempy+1));
        }
   }
}
int main()
{
    int t;
    cin>>n>>m>>t;
    int sx,sy,es,ey;
    cin>>sx>>sy>>es>>ey;
    use.resize(n+1,vector<bool>(m+1,true));
    counts.resize(n+1,vector<long long int>(m+1,0));
    counts[sx][sy]=1;
    for(int i=0;i<t;i++)
    {
        int x,y;
        cin>>x>>y;
        use[x][y]=false;
    }
    BFS(sx,sy);
    cout<<counts[es][ey];
    return 0;
}
/*
3 3 1
1 1 2 2
1 2

1 0 1
1 1 1
1 1 1
*/