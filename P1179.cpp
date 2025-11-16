#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int left;
    int right;
    cin>>left>>right;
    int count=0;
    for(int i=left;i<=right;i++)
    {
        int temp=i;
        while(temp!=0)
        {
            if(temp%10==2)
            {
                count++;
            }
            temp=temp/10;
        }
    }
    cout<<count;
    return 0;
}