#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int Solution(vector<int>&path,int left,int right)
{
    if(left==right)
    {
        return path[left];
    }
    int n=path.size();
    int min = path[left];
    int mindex=left;
    bool equal=true;
    for(int i=left;i<=right;i++)
    {
        if(path[i]<path[min])
        {
            equal=false;
            min=path[i];
            mindex=i;
        }
        else if(path[i]>path[min])
        {
            equal=false;
        }
    }
    if(equal==true)
    {
        return min;
    }
    accumulate(path.begin()+left,path.begin()+right+1,-1*min);
    return min+Solution(path,left,mindex)+Solution(path,mindex,right);
}
int main()
{
    int n;
    cin>>n;
    vector<int>path(n+1);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&path[i]);
    }
    int ans=Solution(path,0,n);
    cout<<ans;
    return 0;
}