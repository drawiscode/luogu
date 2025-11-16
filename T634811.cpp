#include <iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    bool east;
    bool north;
    if(b>0)
    {
        east=true;
    }
    else
    {
        east=false;
    }
    if(a>0)
    {
        north=true;
    }
    else
    {
        north=false;
    }
    if(east&&north)
    {
        cout<<"NorthEast";
    }
    else if(east&&!north)
    {
        cout<<"SouthEast";
    }
    else if(!east&&north)
    {
        cout<<"NorthWest";
    }
    else
    {
        cout<<"SouthWest";
    }
    return 0;
}