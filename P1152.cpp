#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>data(n);
    for(int i=0;i<n;i++)
    {
        cin>>data[i];
    }
    vector<bool>use(n,false);
    for(int i=0;i<n-1;i++)
    {
        if(abs(data[i+1]-data[i])>=n)
        {
            cout<<"Not jolly";
            return 0;
        }
        use[abs(data[i+1]-data[i])]=true;
    }
    for(int i=1;i<=n-1;i++)
    {
        if(use[i]==false)
        {
            cout<<"Not jolly";
            return 0;
        }
    }
    cout<<"Jolly";
    return 0;
}