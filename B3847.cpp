#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int hour;
    int minute;
    int second;
    cin>>hour>>minute>>second;
    char c;
    cin>>c;
    int add;
    if(c=='A')
    {
        add=0;
    }
    else
    {
        add=24*60*60;
    }
    cout<<add+hour*3600+minute*60+second;
    return 0;
}