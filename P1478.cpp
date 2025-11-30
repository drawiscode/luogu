#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<pair<int,int>>apples;
bool cmp(pair<int,int>data1,pair<int,int>data2)
{
    if(data1.second<data2.second)
    {
        return true;
    }
    return false;
}
int main()
{
    int n;
    int s;
    cin>>n>>s;
    int a,b;
    cin>>a>>b;
    int max_h=a+b;
    apples.resize(n);
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        apples[i]=make_pair(x,y);
    }
    sort(apples.begin(),apples.end(),cmp);
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(s<=0)
        {
            break;
        }
        if(apples[i].second<=s&&apples[i].first<=max_h)
        {
            count++;
            s-=apples[i].second;
        }
    }
    cout<<count;
    return 0;
}
/*
8 15
20 130
120 3
150 2
110 7
180 1
50 8
200 0
140 3
120 2
*/