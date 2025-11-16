#include <iostream>
#include <vector>
#include <string>
using namespace std;
int Cal(string t)
{
    //1:12
    if(t[1]==':')
    {
        int hour=t[0]-'0';
        int minite=(t[2]-'0')*10+t[3]-'0';
        return hour*60+minite;
    }
    else//11:12
    {
        int hour=(t[0]-'0')*10+t[1]-'0';
        int minite=(t[3]-'0')*10+t[4]-'0';
        return hour*60+minite;
    }
}
int main()
{
    string time1;
    string time2;
    int n;
    cin>>time1>>time2>>n;
    
    vector<int>cnts(n+1);
    vector<int>weights(n+1);
    vector<int>vals(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>weights[i]>>vals[i]>>cnts[i];
    }

    int t=Cal(time2)-Cal(time1);
    vector<long long int>f(t+1,0);
    
    for(int i=1;i<=n;i++)
    {
        if(cnts[i]==0)//完全背包
        {
            for(int j=weights[i];j<=t;j++)
            {
                f[j]=max(f[j],f[j-weights[i]]+vals[i]);
            }
        }
        else 
        {
            for(int j=t;j>=weights[i];j--)
            {
                for(int k=1;k<=cnts[i]&&j>=weights[i]*k;k++)
                {
                    f[j]=max(f[j],f[j-weights[i]*k]+vals[i]*k);
                }
            }
        }
    }
    cout<<f[t];
    return 0;
}