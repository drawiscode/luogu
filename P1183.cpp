#include <iostream>
#include <vector>
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

    int sum=0;

    for(int i=0;i<n-1;i++)
    {
        int xi=points[i].first;
        int yi=points[i].second;
        int xj=points[i+1].first;
        int yj=points[i+1].second;
        sum+=xi*yj-xj*yi;
    }
    sum=abs(sum)/2;
    cout<<sum;
    return 0;
}