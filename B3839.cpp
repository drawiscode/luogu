#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
using namespace std;
vector<int>ans;
int main()
{
    int n;
    cin>>n;
    ans.resize(n+1,0);
    ans[1]=1;
    for(int i=2;i<=n;i++)
    {
        ans[i]=ans[i-1]+i;
    }
    cout<<accumulate(ans.begin(),ans.end(),0);
    return 0;
}