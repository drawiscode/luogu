#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>datas(n);
    vector<int>sort_datas(n);
    for(int i=0;i<n;i++)
    {
        cin>>datas[i];
    }
    sort(sort_datas.begin(),sort_datas.end(),less<int>());
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(datas[i]!=sort_datas[i])
        {
            for(int j=i+1;j<n;j++)
            {
                if(datas[j]==sort_datas[i])
                {
                    int temp=datas[j];
                    datas[j]=datas[i];
                    datas[i]=temp;
                    break;
                }
            }
            count++;
        }
    }
    cout<<count;
    return 0;
}