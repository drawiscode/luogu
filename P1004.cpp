#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    long long int val;
    pair<int,int>parent;
};
long long int findMaxPath(vector<vector<long long int>>&num,int N)
{
    vector<vector<Node>>ans(N+1,vector<Node>(N+1));
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            ans[i][j].val=num[i][j];
            ans[i][j].parent=make_pair(-1,-1);
        }
    }
    for(int i=2;i<=N;i++)
    {
        ans[i][1].val+=ans[i-1][1].val;
        ans[i][1].parent=make_pair(i-1,1);
    }
    for(int j=2;j<=N;j++)
    {
        ans[1][j].val+=ans[1][j-1].val;
        ans[1][j].parent=make_pair(1,j-1);
    }
    for(int i=2;i<=N;i++)
    {
        for(int j=2;j<=N;j++)
        {
            if(ans[i-1][j].val>=ans[i][j-1].val)
            {
                ans[i][j].val+=ans[i-1][j].val;
                ans[i][j].parent=make_pair(i-1,j);
            }
            else
            {
                ans[i][j].val+=ans[i][j-1].val;
                ans[i][j].parent=make_pair(i,j-1);
            }
        }
    }
    int line=N,col=N;
    while(line!=1||col!=1)
    {
        num[line][col]=0;
        int preline=line;
        int precol=col;
        line=ans[preline][precol].parent.first;
        col=ans[preline][precol].parent.second;
    }
    num[line][col]=0;
    return ans[N][N].val;
}

int main()
{
    int N;
    cin>>N;
    vector<vector<long long int>>num(N+1,vector<long long int>(N+1,0));
    long long int line,col,val;
    cin>>line>>col>>val;
    while(line!=0)
    {   
        num[line][col]=val;
        cin>>line>>col>>val;
    }
    long long int firstans=findMaxPath(num,N);
    long long int secondans=findMaxPath(num,N);
    cout<<firstans+secondans<<endl;
    return 0;
}