#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>queries(n);
    int maxcal=0;
    for(int i=0;i<n;i++)
    {
        cin>>queries[i];
        maxcal=max(maxcal,queries[i]);
    }
    vector<long long int>zeros(maxcal+1,0);
    vector<long long int>ones(maxcal+1,0);
    zeros[2]=0;
    zeros[1]=1;
    ones[1]=0;
    ones[2]=1;
    for(int i=3;i<=maxcal;i++)
    {
        zeros[i]=(zeros[i-1]+zeros[i-2])%1000000007;
        ones[i]=(ones[i-1]+ones[i-2])%1000000007;
    }
    vector<long long int>counts(maxcal+1,0);
    for(int i=3;i<=maxcal;i++)
    {
        counts[i]=(counts[i-1]+counts[i-2])%1000000007;
        counts[i]=(counts[i]+(zeros[i-1]*ones[i-2])%1000000007)%1000000007;
    }
    for(int i=0;i<queries.size();i++)
    {
        cout<<counts[queries[i]]<<endl;
    }
    return 0;
}
/*
2
3
5
*/