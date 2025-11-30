#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    unordered_map<int,int>mp;
    for(int i=1;i<=n;i++)
    {
        int num;
        scanf("%d",&num);
        mp[i]=num;
    }
    vector<int>queries(m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&queries[i]);
    }
    for(int i=0;i<m;i++)
    {
        printf("%d\n",mp[queries[i]]);
    }
    return 0;
}