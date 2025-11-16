#include <iostream>
using namespace std;
int main()
{
    int x;
    int y;
    cin>>x>>y;
    int i=x;
    while(1)
    {
        if((i%x==0)&&(i%y==0))
        {
            cout<<i;
            return 0;
        }
        i++;
    }
}