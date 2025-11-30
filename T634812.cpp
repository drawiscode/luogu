#include <iostream>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    long long int a;
    long long int b;
    cin>>a>>b;
    long long int ans;
    if(n>(b/a))
    {
        ans=b;
    }
    else
    {
        ans=n*a;
    }
    cout<<ans;
    return 0;
}