#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>vals(n+1);
    vector<int>weights(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>weights[i]>>vals[i];
    }
    vector<int>f(m+1,0);
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=weights[i];j--)
        {
            f[j]=max(f[j],f[j-weights[i]]+vals[i]);
        }
    }
    cout<<f[m];
    return 0;
}