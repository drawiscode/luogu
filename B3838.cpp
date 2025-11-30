#include <iostream>
using namespace std;
int main()
{
    int hour1;
    int minute1;
    int hour2;
    int minute2;
    cin>>hour1>>minute1>>hour2>>minute2;
    cout<<hour2*60+minute2-hour1*60-minute1;
    return 0;
}