#include <iostream>
#include <vector>
using namespace std;
vector<int>datas;
vector<vector<int>>dp;
//2 4 
//3 2
void Print()
{
    int n=datas.size();
    int m=dp[0].size();
    n--;
    m--;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    datas.resize(n+1);
    dp.resize(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++)
    {
        cin>>datas[i];
    }
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=0;k<=datas[i];k++)
            {
                if(j-k>=0)
                {
                    dp[i][j]=(dp[i][j]+dp[i-1][j-k])%1000007;
                }
            }
        }
    }
  // Print();
    cout<<dp[n][m];
    return 0;
}
/*int Oper(int u,int m)
{
    int n=sums.size();
    n--;
    if(u==n&&m<=datas[u]||m==0)
    {
        return 1;
    }
    if(u==n&&m>datas[u])
    {
        return 0;
    }
    int sum=0;
    for(int i=0;i<=datas[u]&&m-i>=0;i++)
    {
        sum+=Oper(u+1,m-i)%1000007;
    }
    return sum;
}
int main()
{
    int n,m;
    cin>>n>>m;
    datas.resize(n+1);
    sums.resize(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>datas[i];
        sums[i]=sums[i-1]+datas[i];
    }
    int ans=Oper(1,m)%1000007;
    cout<<ans;
    return 0;
}
*/