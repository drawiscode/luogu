#include <iostream>
#include <vector>
using namespace std;
int main()
{
    //2 5 3
    int x;
    int y;
    int z;
    cin>>x>>y>>z;
    int n;
    cin>>n;
    int sum=x*2+5*y+3*z;
    if(sum>n)
    {
        cout<<"No"<<endl<<sum-n;
        return 0;
    }
    else
    {
        cout<<"Yes"<<endl<<n-sum;
        return 0;
    }
}