#include <iostream>
#include <cstring>
using namespace std;
const int  N = 51;
int mood[N][N];
long long int ans[N][N][N][N];
int main()
{
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>mood[i][j];
        }
    }
    memset(ans,0,sizeof(ans));
    //i,j,k,l
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=m;k++)
            {
                for(int l=1;l<=n;l++)
                {
                    ans[i][j][k][l]=max(max(ans[i-1][j][k-1][l],ans[i-1][j][k][l-1]),max(ans[i][j-1][k-1][l],ans[i][j-1][k][l-1]))+mood[i][j]+mood[k][l];
                    if(i==k&&j==l)
                    {
                        ans[i][j][k][l]-=mood[i][j];
                    }
                }
            }
        }
    }
    cout<<ans[m][n][m][n]<<endl;
    return 0;
}