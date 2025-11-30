#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
    int n;
    cin>>n;
    int w;
    cin>>w;
    vector<int>weights(n);
    for(int i=0;i<n;i++)
    {
        cin>>weights[i];
    }
    sort(weights.begin(),weights.end(),less<int>());
    vector<bool>use(n,false);
    int count;
    return 0;
}