#include <string>
#include <iostream>
using namespace std;
int main()
{
    string str;
    int n;
    cin>>n>>str;
    n=n%26;
    int len=str.size();
    for(int i=0;i<len;i++)
    {
        if(str[i]+n>'z')
        {
            int need='z'-str[i];
            str[i]='a'+(n-need-1);
        }
        else
        {
            str[i]+=n;
        }
    }
    cout<<str;
    return 0;
}