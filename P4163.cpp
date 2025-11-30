/*
5
1 3 4 2 5
2 5 4 2 1
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<long long int>a(n);
    vector<long long int>b(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    vector<long long int>dpa(n);
    vector<long long int>dpb(n);
    dpa[0]=0;
    dpb[0]=0;
    for(int i=1;i<n;i++)
    {
        dpa[i]=min(dpa[i-1]+abs(a[i-1]-a[i]),dpb[i-1]+abs(b[i-1]-a[i]));
        dpb[i]=min(dpa[i-1]+abs(a[i-1]-b[i]),dpb[i-1]+abs(b[i]-b[i-1]));
    }
    cout<<min(dpa[n-1],dpb[n-1]);
    return 0;
}