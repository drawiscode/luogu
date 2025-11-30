#include <string>
#include <vector>
#include <iostream>

using namespace std;
int main()
{
    int n=5;
    string data1;
    getline(cin,data1);
    int ans=0;
    for(int i=0;i<data1.size();i++)
    {
        if(!(data1[i]==' '||data1[i]=='\n'))
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}