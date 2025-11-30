#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;
int main()
{
    double x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    double s1=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    double s2=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
    double s3=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
    cout<<fixed<<setprecision(2)<<s1+s2+s3;
    return 0;
}