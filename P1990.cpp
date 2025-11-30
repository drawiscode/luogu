#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>F(n+1,0);
    vector<int>G(n+2,0);
    F[1]=1;
    F[2]=2;
    G[3]=1;
    for(int i=3;i<=n;i++)
    {
        F[i]=(F[i-1]%10000+F[i-2]%10000+2*G[i]%10000)%10000;
        //G[i]=F[i-3]+G[i-1];
        G[i+1]=(F[i-2]%10000+G[i]%10000)%10000;
    }
    cout<<F[n];
    return 0;
}
/*
11

*/