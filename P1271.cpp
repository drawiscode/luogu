#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>data;
    for(int i=0;i<m;i++)
    {
        int node;
        scanf("%d",&node);
        data.emplace_back(node);
    }
    sort(data.begin(),data.end(),less<int>());
    for(int i=0;i<m;i++)
    {
        printf("%d ",data[i]);
    }
    return 0;
}