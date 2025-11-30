#include <iostream>
using namespace std;
int main()
{
    int height[10];
    for(int i=0;i<10;i++)
    {
        cin>>height[i];
    }
    int count=0;
    int h;
    cin>>h;
    for(int i=0;i<10;i++)
    {
        if(h+30>=height[i])
        {
            count++;
        }
    }
    cout<<count;
    return 0;
}