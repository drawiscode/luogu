#include <iostream>
#include <vector>
using namespace std;
vector<int>ans;
void Mul()
{
    for(int i=0;i<ans.size();i++)
    {
        ans[i]*=2;
    }
    for(int i=0;i<ans.size();i++)
    {
        if(ans[i]>=10)
        {
            if(i==ans.size()-1)
            {
                ans.emplace_back(ans[i]/10);
                ans[i]=ans[i]%10;
            }
            else
            {
                ans[i+1]+=ans[i]/10;
                ans[i]=ans[i]%10;
            }
        }
    }
}
int main()
{
    int p;
    cin>>p;
    ans.emplace_back(1);
    while(p>0)
    {
        Mul();
        p--;
    }
    int index=ans.size()-1;
    while(ans[index]==0)
    {
        index--;
    }
    cout<<index+1<<endl;
    ans[0]--;
    vector<int>result;
    for(int i=0;i<=index;i++)
    {
        result.emplace_back(ans[i]);
    }
    for(int i=index+1;i<=500;i++)
    {
        result.emplace_back(0);
    }
    for(int i=499;i>=0;i--)
    {
        cout<<result[i];
        if(i%50==0&&i!=500)
        {
            cout<<endl;
        }
    }
    return 0;
}