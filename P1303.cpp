#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    string num1;
    string num2;
    cin>>num1>>num2;
    reverse(num1.begin(),num1.end());
    reverse(num2.begin(),num2.end());
    int k=max(num1.size(),num2.size());
    vector<int>ans(2*k,0);
    for(int i=0;i<num1.size();i++)
    {
        for(int j=0;j<num2.size();j++)
        {
            ans[i+j]+=num1[i]*num2[j];
        }
    }
    for(int i=0;i<2*k;i++)
    {
        if(ans[i]>=10)
        {
            ans[i+1]+=ans[i]/10;
            ans[i]=ans[i]%10;
        }
    }
    for(int i=2*k-1;i>=0;i--)
    {
        printf("%d",ans[i]);
    }
    return 0;
}