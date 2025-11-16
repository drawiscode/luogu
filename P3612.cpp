#include <iostream>
#include <vector>
#include <string>
using namespace std;
string str;
long long int n;
int ans;
void Trace(long long int u)
{
    long long int sum=str.size();
    while(sum<u)
    {
        sum*=2;
    }
    if(u<=str.size())
    {
        ans=u-1;
        return;
    }
    long long int temp=sum/2;
    long long int next;
    if(u==temp+1)
    {
        next=temp;
    }
    else
    {
        next=u-1;
        next-=temp;
    }
    Trace(next);
}
/*
COW -> COWWCO -> COWWCO  OCOWWC 8 C
                          C
                          ABCDEFGHIJKLMNOPQRSTUVWXYZ 2222222222
*/
int main()
{
    cin>>str>>n;
    //long long int sum=str.size();

    Trace(n);
    cout<<str[ans];
    return 0;
}