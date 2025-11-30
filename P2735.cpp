#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    ll p;
    cin>>p;
    
    ll B=gcd(n,m)+gcd(abs(p-n),m)+p;

    ll area=p*m;
    ll ans=(area-B+2)/2;
    cout<<ans;
    return 0;
}