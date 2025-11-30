#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
bool Judge(int u)
{
    if(u==0||u==1)
    {
        return false;
    }
    if(u==2)
    {
        return true;
    }
    for(int i=2;i<=sqrt(u);i++)
    {
        if(u%i==0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string str;
    cin>>str;
    int n=str.size();
    vector<int>counts(26,0);
    int maxcount=-1;
    int mincount=101;
    for(int i=0;i<n;i++)
    {
        counts[str[i]-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        if(counts[i]>maxcount&&counts[i]!=0)
        {
            maxcount=counts[i];
        }
        if(counts[i]<mincount&&counts[i]!=0)
        {
            mincount=counts[i];
        }
    }
    int ans=maxcount-mincount;
    if(Judge(ans))
    {
        cout<<"Lucky Word"<<endl<<ans;
    }
    else
    {
        cout<<"No Answer"<<endl<<0;
    }
    return 0;
}