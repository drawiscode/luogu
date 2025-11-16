#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>data(n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data[i]);
    }
    sort(data.begin(),data.end(),less<int>());
    for(int i=0;i<n;i++)
    {
        printf("%d ",data[i]);
    }
    return 0;
}