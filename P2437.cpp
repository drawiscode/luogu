#include <iostream>
#include <vector>
using namespace std;
//2 10 1 9
vector<vector<int>>datas;
void Add(int u)
{   
    datas[u].resize(datas[u-1].size()+1,0);
    for(int i=0;i<datas[u-2].size();i++)
    {
        datas[u][i]+=datas[u-2][i];
    }
    for(int i=0;i<datas[u-1].size();i++)
    {
        datas[u][i]+=datas[u-1][i];
    }
    for(int i=0;i<datas[u].size()-1;i++)
    {
        if(datas[u][i]>=10)
        {
            datas[u][i+1]+=datas[u][i]/10;
            datas[u][i]=datas[u][i]%10;
        }
    }
}
int main()
{
    int m,n;
    cin>>m>>n;
    n=n-m+1;
    m=1;
    datas.resize(n+1);
    datas[1].emplace_back(1);
    datas[2].emplace_back(1);
    for(int i=3;i<=n;i++)
    {
        Add(i);
    }
    int index=datas[n].size()-1;
    while(datas[n][index]==0)
    {
        index--;
    }
    for(;index>=0;index--)
    {
        cout<<datas[n][index];
    }
    return 0;
}