#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void mySwap(long long int& data1,long long int& data2)
{
    long long int temp=data1;
    data1=data2;
    data2=temp;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    vector<int>queres(T);
    int maxn=-1;
    for(int i=0;i<T;i++)
    {
        cin>>queres[i];
        maxn=max(maxn,queres[i]);
    }

    vector<int>sortQueres=queres;
    sort(sortQueres.begin(),sortQueres.end(),less<int>());

    vector<long long int>datas(maxn+1,0);
    datas[1]=1;
    datas[2]=1;
    datas[3]=1;
    int cur=4;
    
    vector<long long int>ans;
    long long int x1=1;
    long long int x2=1;
    long long int x3=1;
    long long int x4=1;
    for(int i=0;i<T;i++)
    {
        int quere=sortQueres[i];
        while(quere>=cur)
        {
            x4=(x1+x3)%1000000007;
            cur++;
            if(quere<cur)
            {

            }
        }
    }
    return 0;
}