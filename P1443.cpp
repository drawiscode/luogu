#include <iostream>
#include <vector>
#include <cstdint>
#include <queue>
#include <tuple>
using namespace std;
vector<vector<int>>mp;
int n;
int m;
bool Judge(int x,int y)
{
    if((x>0)&&(x<=n)&&(y>0)&&(y<=m))
    {
        return true;
    }
    return false;
}
void BFS(int x,int y)
{
    queue<tuple<int,int,int>>q;
    q.push(make_tuple(x,y,0));
    //int count=1;
    vector<pair<int,int>>temp(8);
    temp[0]=make_pair(-1,-2);
    temp[1]=make_pair(-2,-1);
    temp[2]=make_pair(-1,2);
    temp[3]=make_pair(-2,1);
    temp[4]=make_pair(1,-2);
    temp[5]=make_pair(2,-1);
    temp[6]=make_pair(1,2);
    temp[7]=make_pair(2,1);
    while(q.empty()==false)
    {
        int ux=get<0>(q.front());
        int uy=get<1>(q.front());
        int count=get<2>(q.front());
        q.pop();
        for(int i=0;i<temp.size();i++)
        {
            int addx=temp[i].first;
            int addy=temp[i].second;
            if(Judge(ux+addx,uy+addy)&&count+1<mp[ux+addx][uy+addy])
            {
                mp[ux+addx][uy+addy]=count+1;
                q.push(make_tuple(ux+addx,uy+addy,count+1));
            }
        }
    }
}
int main()
{
    //int n,m;
    cin>>n>>m;
    mp.resize(n+1,vector<int>(m+1,INT32_MAX));
    int x,y;
    cin>>x>>y;
    mp[x][y]=0;
    BFS(x,y);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(mp[i][j]==INT32_MAX)
            {
                cout<<-1<<" ";
            }
            else
            {
                cout<<mp[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
/*
3 3 1 1

*/