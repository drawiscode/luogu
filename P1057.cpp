#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    int m;
    cin>>n>>m;
    vector<int>ans(n+1,0);
    ans[1]=1;
    for(int i=0;i<m;i++)
    {
        vector<int>temp(n+1,0);
        for(int j=1;j<=n;j++)
        {
            int left=j-1;
            int right=j+1;
            if(left==0)
            {
                left+=n;
            }
            if(right==n+1)
            {
                right=1;
            }
            temp[j]=ans[left]+ans[right];
        }
        ans=temp;
    }
    cout<<ans[1];
    return 0;
}