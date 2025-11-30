#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;
void PreHandle(vector<int>&masks,int m)
{
    for(int i=0;i<(1<<m);i++)
    {
        bool legal=true;
        for(int j=0;j<=m;j++)
        {
            if(((i>>j)&3)==3)
            {
                legal=false;
                break;
            }
        }
        if(legal)
        {
            masks.emplace_back(i);
        }
    }
}
int Sum(vector<vector<int>>&datas,int i,int j)
{
    int m=datas[0].size();
    int sum=0;
    for(int k=0;k<m;k++)
    {
        if(((j>>k)&1)==1)
        {
            sum+=datas[i][m-1-k];
        }
    }
    return sum;
}
void Oper()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>datas(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>datas[i][j];
        }
    }
    vector<int>masks;
    PreHandle(masks,m);
    vector<vector<int>>dp(n,vector<int>(1<<m,-1));

    for(int i=0;i<masks.size();i++)
    {
        dp[0][masks[i]]=0;
        for(int j=0;j<m;j++)
        {
            if(((masks[i]>>j)&1)==1)
            {
                dp[0][masks[i]]+=datas[0][m-1-j];
            }
        }
    }

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<masks.size();j++)//上一行
        {
            for(int k=0;k<masks.size();k++)//当前行
            {
                if((((masks[k]>>1)&(masks[j]))==0)&&(((masks[k]<<1)&(masks[j]))==0)&&((masks[k]&masks[j])==0))
                {
                    dp[i][masks[k]]=max(dp[i-1][masks[j]]+Sum(datas,i,masks[k]),dp[i][masks[k]]);
                }
            }
        }
    }
    int ans=-1;
    for(int i=0;i<masks.size();i++)
    {
        if(ans<dp[n-1][masks[i]])
        {
            ans=dp[n-1][masks[i]];
        }
    }
    cout<<ans<<endl;
}
int main()
{
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        Oper();
    }
    return 0;
}
/*
1
1 3 
87 70 85



1
2 2
67 75 
29 29 
*/