#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>datas(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>datas[i][j];
        }
    }
    vector<vector<int>>ans(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            ans[i][j]=ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1]+datas[i][j];
        }
    }

    int maxans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int p=1;p<=i;p++)
            {
                for(int q=1;q<=j;q++)
                {
                    maxans=max(maxans,ans[i][j]-(ans[p-1][j]+ans[i][q-1]-ans[p-1][q-1]));
                }
            }
        }
    }
    cout<<maxans;
    return 0;
}