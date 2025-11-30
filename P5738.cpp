#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    double maxscore=0;
    for(int i=0;i<n;i++)
    {
        double sum=0;
        double max1=0;
        double min1=11;
        for(int j=0;j<m;j++)
        {
            double x;
            cin>>x;
            if(max1<x)
            {
                max1=x;
            }
            if(min1>x)
            {
                min1=x;
            }
            sum+=x;
        }
        sum=sum-max1-min1;
        if(sum>maxscore)
        {
            maxscore=sum;
        }
    }
    cout<<fixed<<setprecision(2)<<maxscore/(m-2);
    return 0;
}
/*
7 6
4 7 2 6 10 7
0 5 0 10 3 10
2 6 8 4 3 6
6 3 6 7 5 8
5 9 3 3 8 1
5 9 9 3 2 0
5 8 0 4 1 10

*/