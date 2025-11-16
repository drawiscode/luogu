#include <iostream>
#include <string>
using namespace std;
int main()
{
    string datas;
    cin>>datas;
    int n=datas.size();
    int add='A'-'a';
    for(int i=0;i<n;i++)
    {
        if(datas[i]<='z'&&datas[i]>='a')
        {
            datas[i]+=add;
        }
    }
    cout<<datas;
    return 0;
}