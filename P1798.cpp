#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int height;
    int n;
    int count;
    cin>>height>>n>>count;
    vector<long long int>times(n);
    int add=0;
    for(int i=0;i<n;i++)
    {
        int h,sign;
        cin>>h>>sign;
        if(sign==0)
        {
            add++;
            times[i]=height-h;
        }
        else 
        {
            times[i]=height-1+h-1;
        }
    }
    count+=add;
    sort(times.begin(),times.end(),less<int>());
    long long int ans=0;
    while(1)
    {
        if(ans*n<count)
        {
            ans++;
        }
        else
        {
            break;
        }
    }
    ans--;
    long long int temp=count-ans*n;
    cout<<ans*2*(height-1)+times[temp-1];
    return 0;
}
/*
5 2 4
1 0
3 0


*/