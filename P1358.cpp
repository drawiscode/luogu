#include <iostream>
#include <vector>
using namespace std;
int C(int n,int k)
{
    //
    int sum=0;
    for(int i=k+1;i<=n;i++)
    {
        sum;
    }
}
int A(int n,int k)
{

}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>requests;
    int k=0;
    for(int i=0;i<m;i++)
    {
        int node;
        cin>>node;
        if(node!=0)
        {
            k+=node;
            requests.emplace_back(node);
        }
    }
    int ans=0;
    for(int i=1;i<requests.size();i++)
    {
        ans=(ans%10007+A(k,requests[i])%10007)%10007;
    }

    return 0;
}