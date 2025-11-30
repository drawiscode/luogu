/*
8
186 186 150 200 160 130 197 220
*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>datas(n);
    //vector<int>dp_left(n);
   // vector<int>dp_right(n);
    vector<int>count_left(n,1);
    vector<int>count_right(n,1);
    for(int i=0;i<n;i++)
    {
        cin>>datas[i];
    }
   // dp_left[0]=datas[0];
   // dp_right[n-1]=datas[n-1];
   // count_left[0]=1;
   // count_right[n-1]=1;
    for(int i=1;i<n;i++)
    {
       // dp_left[i]=datas[i];
        for(int j=0;j<i;j++)
        {
            if(datas[i]>datas[j])
            {
                count_left[i]=max(count_left[i],count_left[j]+1);
            }
        }
    }
    for(int i=n-2;i>=0;i--)
    {
    //    dp_right[i]=datas[i];
        for(int j=n-1;j>i;j--)
        {
            if(datas[i]>datas[j])
            {
                count_right[i]=max(count_right[i],count_right[j]+1);
            }
        }
    }
    int ans=0;
    for(int k=0;k<n;k++)
    {
        int l_count=0;
        for(int i=0;i<k;i++)
        {
            if((datas[i]<datas[k])&&(count_left[i]>l_count))
            {
                l_count=count_left[i];
            }
        }
        int r_count=0;
        for(int i=n-1;i>k;i--)
        {
            if((datas[i]<datas[k])&&(count_right[i]>r_count))
            {
                r_count=count_right[i];
            }
        }
        ans=max(1+l_count+r_count,ans);
    }
    cout<<n-ans;
    return 0;   
}
/*
10
1 2 3 4 5 10 8 7 9 6
*/