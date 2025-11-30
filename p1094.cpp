#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>prices(m);
    for(int i=0;i<m;i++)
    {
        cin>>prices[i];
    }
    vector<bool>use(m,false);
    sort(prices.begin(),prices.end(),less<int>());
    int count=0;    
    for(int i=0;i<m;i++)
    {
        if(use[i]==false)
        {
            bool find=false;
            for(int j=m-1;j>i;j--)
            {
                if(use[j]==true)
                {
                    continue;
                }
                else if(prices[j]+prices[i]<=n)
                {
                    use[i]=true;
                    use[j]=true;
                    count++;
                    find=true;
                    break;
                }
            }
            if(find==false)
            {
                use[i]=true;
                count++;
            }
        }
    }
    cout<<count;
    return 0;
}