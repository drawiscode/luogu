#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i=1;
    while(1)
    {
        if(i*i*i==n)
        {
            cout<<"Yes";
            return 0;
        }
        else if(i*i*i>n)
        {
            cout<<"No";
            return 0;
        }
        i++;
    }
}