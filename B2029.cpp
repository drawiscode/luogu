#include <iostream>
using namespace std;
int main()
{
    int h;
    int r;
    cin>>h>>r;
    double V=3.14*r*r*h;
    double num = 20000 / V;
    cout<< (int)num + 1;
    return 0;
}