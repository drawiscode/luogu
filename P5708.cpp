#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    double a, b, c;
    scanf_s("%lf%lf%lf", &a, &b, &c);
    double p = 0.5 * (a + c + b);
    cout << fixed << setprecision(1) << sqrt(p * (p - a) * (p - b) * (p - c));
    return 0;
}