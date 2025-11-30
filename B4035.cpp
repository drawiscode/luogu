#include <iostream>
using namespace std;
int main()
{
    int n;
    int count=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int node;
        cin>>node;
        if((node%9==0)&&(node%8!=0))
        {
            count++;
        }
    }
    cout<<count;
    return 0;
}