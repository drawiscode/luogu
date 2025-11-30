#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>

using namespace std;

vector<pair<int,int>>points;

int main()
{

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        points.emplace_back(make_pair(x,y));
    }
    double ans=1000000000;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int xi=points[i].first;
            int yi=points[i].second;
            int xj=points[j].first;
            int yj=points[j].second;

            double distance=sqrt((xi-xj)*(xi-xj)+(yi-yj)*(yi-yj));
            ans=min(ans,distance);
        }
    }
    cout<<fixed<<setprecision(4)<<ans;
    return 0;
}