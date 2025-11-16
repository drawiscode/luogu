#include <iostream>
#include <vector>
using namespace std;
vector<bool>is_primes;
vector<int>datas;
int ans;
void Cal_Prime()
{
    int n=is_primes.size();
    n--;
    is_primes[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_primes[i]==true)
        {
            for(int j=2*i;j<=n;j+=i)
            {
                is_primes[j]=false;
            }
        }
        else
        {
            continue;
        }
    }
}
void TraceBack(int i,int k,int sum)
{
    int n=datas.size();
    n--;
    if(k==0)
    {
        if(is_primes[sum]==true)
        {
            ans++;
        }
        return;
    }
    else if(i==n+1)
    {
        return;
    }
    else
    {
        TraceBack(i+1,k,sum);
        TraceBack(i+1,k-1,sum+datas[i]);
    }
}
int main()
{
    int n;
    int k;
    cin>>n>>k;
    ans=0;
    datas.resize(n+1);
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>datas[i];
        sum+=datas[i];
    }
    is_primes.resize(sum+1,true);
    Cal_Prime();

    TraceBack(1,k,0);
    cout<<ans;
    return 0;
}