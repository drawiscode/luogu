#include <iostream>
#include <vector>
struct Node
{
    vector<int>num; 
};
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<vector<vector<Node>>>dp(n+1,vector<vector<Node>>(n+1,vector<Node>(n+1)));//dp[i][j][k] 跑第i次还j圈,这次跑了k圈
    vector<int>temp;
    temp.emplace_back(0);
    dp[0][n][0].num=temp;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            for(int k=i;k<=n;k++)
            {
                for;
            }
        }
    }
    return 0;
}