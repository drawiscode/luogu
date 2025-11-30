#include <iostream>
#include <vector>
using namespace std;
vector<bool>is_primes;
void Prime()
{
    is_primes[1]=false;
    for(int i=2;i<=100000;i++)
    {
        if(is_primes[i]==true)
        {
            for(int j=2*i;j<=100000;j+=i)
            {
                is_primes[j]=false;
            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    is_primes.resize(100001,true);
    Prime();
    vector<int>datas;
    for(int i=0;i<n;i++)
    {
        int node;
        cin>>node;
        if(is_primes[node]==true)
        {
            datas.emplace_back(node);
        }
    }
    for(int i=0;i<datas.size();i++)
    {
        cout<<datas[i]<<" ";
    }
    return 0;
}

