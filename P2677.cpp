#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n,b;
    cin>>n>>b;
    vector<int>heights(n+1,0);
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>heights[i];
        sum+=heights[i];
    }
    vector<bool>ans(sum+1,false);
    ans[0]=true;
    for(int i=1;i<=n;i++)
    {
        for(int j=sum;j>0;j--)
        {
            if(j>=heights[i])
            {
                ans[j]=ans[j-heights[i]]||ans[j];
            }
        }
    }
    int ans1=0;
    for(int i=b;i<=sum;i++)
    {
        if(ans[i])
        {
            ans1=ans[i];
            break;
        }
    }
    cout<<ans1;
    return 0;
}