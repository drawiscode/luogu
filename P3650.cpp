#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int>heights(101, 0);
    for(int i=0;i<n;i++)
    {
        int node;
        cin>>node;
        heights[node]++;
    }
    int ans=10000001;
    for(int i=0;i<=83;i++)
    {
        int low=i;
        int high=low+17;
        int sum=0;
        for(int j=0;j<low;j++)
        {
            sum+=(low-j)*(low-j)*heights[j];
        }
        for(int j=100;j>high;j--)
        {
            sum+=(j-high)*(j-high)*heights[j];
        }
        ans=min(ans,sum);
    }
    cout << ans;
    return 0;
}