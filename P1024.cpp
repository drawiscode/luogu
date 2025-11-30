#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;
double parame[4];
//1 -1 -6 9
double Cal(double x)
{
    /*if (x == 1)
    {
        cout << endl;
    }*/
    double a = parame[0];
    double b = parame[1];
    double c = parame[2];
    double d = parame[3];
    return a * x * x * x + b * x * x + c * x + d;//ax
}
void Oper(double left, double right)
{
    double precision = 100;
    double x;
    for (double i = left; i <= right; i += 0.001)
    {
        double this_ans = abs(Cal(i));
        if (this_ans < precision)
        {
            precision = this_ans;
            x = i;
        }
    }
    cout << fixed << setprecision(2) << x << " ";
}
int main()
{
    cin >> parame[0] >> parame[1] >> parame[2] >> parame[3];
    double pre = Cal(-200);
    int count = 0;
    for (double x = -200; x <= 100; x++)
    {
        /*if (x == 1)
        {
            cout << endl;
        }*/
        double cur = Cal(x);
        if (cur == 0)
        {
            count++;
            cout << fixed << setprecision(2) << x << " ";
            if (count == 3)
            {
                break;
            }
        }
        else if (pre * cur < 0)
        {
            Oper(x - 1, x);
        }
        pre = cur;
    }
    return 0;
}