#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair<int,int>data1,pair<int,int>data2)
{
    if(data1.first<data2.first)
    {
        return true;
    }
    return false;
}
int main()
{
    cout<<"罗文宇"<<endl;
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>cow(m);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        cow[i]=make_pair(x,y);
    }
    sort(cow.begin(),cow.end(),cmp);
    long long int money=0;
    for(int i=0;i<m;i++)
    {
        if(n>cow[i].second)
        {
            money+=cow[i].second*cow[i].first;
            n-=cow[i].second;
        }
        else 
        {
            money+=cow[i].first*n;
            break;
        }
    }
    cout<<money;
    return 0;
}
/*
100 5
5 20
9 40
3 10
8 80
6 30

*/