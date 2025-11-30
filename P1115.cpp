#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>datas(n+1,0);
    vector<int>ans(n+1,0);
    int maxans=-10001;
    for(int i=1;i<=n;i++)
    {
        cin>>datas[i];
        ans[i]=max(ans[i-1]+datas[i],datas[i]);
        maxans=max(maxans,ans[i]);
    }
    cout<<maxans;
    return 0;
}