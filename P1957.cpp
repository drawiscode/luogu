#include <iostream>
#include <vector>
#include <string>
using namespace std;
int Cal(int x)
{
    if(x==0)
    {
        return 1;
    }
    int num=0;
    if(x<0)
    {
        x=-x;
        num++;
    }
    while(x!=0)
    {
        x=x/10;
        num++;
    }
    return num;
}
int main()
{
    int n;
    cin>>n;
    char pre;
    for(int i=0;i<n;i++)
    {
        string data1;
        cin>>data1;
        if(data1[0]=='a')
        {
            pre='a';
            int x,y;
            cin>>x>>y;
            cout<<x<<"+"<<y<<"="<<x+y<<endl;
            cout<<2+Cal(x)+Cal(y)+Cal(x+y)<<endl;
        }
        else if(data1[0]=='b')
        {
            pre='b';
            int x,y;
            cin>>x>>y;
            cout<<x<<"-"<<y<<"="<<x-y<<endl;
            cout<<2+Cal(x)+Cal(y)+Cal(x-y)<<endl;
        }
        else if(data1[0]=='c')
        {
            pre='c';
            int x,y;
            cin>>x>>y;
            cout<<x<<"*"<<y<<"="<<x*y<<endl;
            cout<<2+Cal(x)+Cal(y)+Cal(x*y)<<endl;
        }
        else 
        {
            int x=0;
            int y;
            cin>>y;
            for(int j=0;j<data1.size();j++)
            {
                x=x*10+(data1[j]-'0');
            }
            if(pre=='a')
            {
                cout<<x<<"+"<<y<<"="<<x+y<<endl;
                cout<<2+Cal(x)+Cal(y)+Cal(x+y)<<endl;
            }
            else if(pre=='b')
            {
                cout<<x<<"-"<<y<<"="<<x-y<<endl;
                cout<<2+Cal(x)+Cal(y)+Cal(x-y)<<endl;
            }
            else if(pre=='c')
            {
                cout<<x<<"*"<<y<<"="<<x*y<<endl;
                cout<<2+Cal(x)+Cal(y)+Cal(x*y)<<endl;
            }
        }
    }

    return 0;
}
/*
5
b 64 46
275 125
11 99
a 46 64
c 99 99
*/