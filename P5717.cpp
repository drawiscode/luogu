#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int>datas(3);
    cin>>datas[0]>>datas[1]>>datas[2];
    sort(datas.begin(),datas.end(),less<int>());
    int a=datas[0];
    int b=datas[1];
    int c=datas[2];
    if(a+b<=c)
    {
        cout<<"Not triangle"<<endl;
        return 0;
    }
    if(a*a+b*b==c*c)
    {
        cout<<"Right triangle"<<endl;
    }
    if(a*a+b*b>c*c)
    {
        cout<<"Acute triangle"<<endl;
    }
    if(a*a+b*b<c*c)
    {
        cout<<"Obtuse triangle"<<endl;
    }
    if(a==b||b==c||a==c)
    {
        cout<<"Isosceles triangle"<<endl;
    }
    if(a==b&&a==c)
    {
        cout<<"Equilateral triangle"<<endl;
    }
    return 0;
}