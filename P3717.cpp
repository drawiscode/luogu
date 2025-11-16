#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>matrix(n+1,vector<int>(n+1,0));
    int m;
    int r;
    cin>>m>>r;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        matrix[x][y]=1;
        for(int p=1;p<=n;p++)
        {
            for(int q=1;q<=n;q++)
            {
                double x1=(double)x-(double)p;
                double y1=(double)y-(double)q;
                double distance=(double)sqrt(x1*x1+y1*y1);
                if(distance<=(double)r)
                {
                    matrix[p][q]=1;
                }
            }
        }
    }
    int count=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(matrix[i][j]==1)
            {
                count++;
            }
        }
    }
    cout<<count;
    return 0;
}