#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>data(n);
    for(int i=0;i<n;i++)
    {
        cin>>data[i];
    }
    for(int i=0;i<n;i++)
    {
        int count=0;
        for(int j=i-1;j>=0;j--)
        {
            if(data[j]<data[i])
            {
                count++;
            }
        }
        cout<<count<<" ";
    }
    return 0;
}