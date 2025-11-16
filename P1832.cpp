#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
using namespace std;
bool Judge(int u)
{
    for(int i=2;i<=sqrt(u);i++)
    {
        if(u%i==0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    vector<int>ans(n+1,0);
    if(n==1)
    {
        return 0;
    }
    else if(n==2||n==3)
    {
        return 1;
    }
    ans[1]=0;
    ans[2]=1;
    ans[3]=1;

    for(int i=4;i<=n;i++)
    {
        for(int j=2;j<i;j++)
        {
            if(Judge(i-j))
            {
                ans[i]+=ans[i-j]+ans[j];
            }
        }
    }
    cout<<ans[n];
    return 0;
}