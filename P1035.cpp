#include <iostream>
using namespace std;
int main()
{
    double k;
    cin>>k;
    double sum=0;
    double count=1;
    while(sum<k)
    {
        sum+=1/count;
        count++;
    }
    cout<<count-1;
    return 0;
}