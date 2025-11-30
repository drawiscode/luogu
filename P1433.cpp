#include <vector>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
vector<vector<double>>dists;
vector<double>init_dists;
vector<double>x;
vector<double>y;
vector<vector<double>>dp;
int main()
{
    int n;
    cin>>n;
    dists.resize(n,vector<double>(n));  
    init_dists.resize(n);
    x.resize(n);
    y.resize(n);
    dp.resize(n,vector<double>(1<<n));
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
        init_dists[i]=sqrt(x[i]*x[i]+y[i]*y[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            double dx=x[i]-x[j];
            double dy=y[i]-y[j];
            dists[i][j]=sqrt(dx*dx+dy*dy);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int mask=0;mask<(1<<n);mask++)
        {
            dp[i][mask]=1000000;
        }
    }//
    for(int i=0;i<n;i++)
    {
        dp[i][1<<i]=init_dists[i];
    }
    for(int mask=0;mask<(1<<n);mask++)
    {
        for(int i=0;i<n;i++)
        {
            if(!(mask&(1<<i)))
            {
                continue;
            }
            else
            {
                for(int j=0;j<n;j++)
                {
                    if(mask&(1<<j))
                    {
                        continue;
                    }
                    else
                    {
                        if(dp[j][mask|(1<<j)]>dp[i][mask]+dists[i][j])
                        {
                            dp[j][mask|(1<<j)]=dp[i][mask]+dists[i][j];
                        }
                    }
                }
            }
        }
    }
    double mindist=1e18;
    for(int i=0;i<n;i++)
    {
        if(mindist>dp[i][(1<<n)-1])
        {
            mindist=dp[i][(1<<n)-1];
        }
    }
    cout<<fixed<<setprecision(2)<<mindist;
    return 0;
}