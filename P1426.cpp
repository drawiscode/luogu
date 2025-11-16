#include <iostream>
#include <vector>
using namespace std;
int main()
{
    double s;
    double x;
    cin >> s >> x;
    double distance = 0;
    double v = 7;
    if (s - x < 0)
    {
        if (v >= s + x)
        {
            cout << "n";
            return 0;
        }
        else
        {
            cout << "y";
            return 0;
        }
    }
    while (1)
    {
        distance += v;
        v = v * 0.98;
        if (distance >= s - x)
        {
            if (distance + v >= s + x)
            {
                cout << "n";
                return 0;
            }
            else
            {
                cout << "y";
                return 0;
            }
        }
    }
    return 0;
}