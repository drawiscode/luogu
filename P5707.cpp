#include<iostream>
#include <string>
using namespace std;
int main()
{
    int s;
    int v;
    cin >> s >> v;
    int time;
    time = s / v ;
    if (s % v != 0)
    {
        time++;
    }
    int time_to_go = 480 - 10 - time;
    if (time_to_go < 0)
    {
        time_to_go += 60 * 24;
    }
    int hour = time_to_go / 60;
    int minite = time_to_go - hour * 60;
    string str_hour;
    string str_minite;
    if (hour < 10)
    {
        str_hour += '0';
    }
    if (minite < 10)
    {
        str_minite += '0';
    }
    str_hour += to_string(hour);
    str_minite += to_string(minite);
    cout << str_hour << ":" << str_minite;
    return 0;
}