#include <iostream>
#include <vector>
using namespace std;
vector<int>eats;
vector<int>different;
int main()
{
    int c,f1,f2,d;
    cin>>c>>f1>>f2>>d;
    eats.resize(d+2,0);
    different.resize(d+2,0);
    for(int i=0;i<c;i++)
    {
        int left;
        int right;
        cin>>left>>right;
        right=min(right,d);
        different[left]+=1;
        different[right+1]-=1;
    }
    eats[1]=different[1];
    for(int i=2;i<=d;i++)
    {
        eats[i]=eats[i-1]+different[i];
    }
    int eaten=f1-f2;
    int index=d;
    while(eaten!=0)
    {
        eaten-=eats[index];
        index--;
    }
    cout<<index+1;
    return 0;
}