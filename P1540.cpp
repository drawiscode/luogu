#include <iostream>
#include <vector>
using namespace std;
bool find(vector<int>&data,int quere)
{
    for(int i=0;i<data.size();i++)
    {
        if(quere==data[i])
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int n;
    int m;
    cin>>n>>m;
    vector<int>data(n,-1);
    int count=0;
    int index=0;
    for(int i=0;i<m;i++)
    {
        int quere;
        scanf("%d",&quere);
        if(find(data,quere)==false)
        {
            data[index]=quere;
            index=(index+1)%n;
            count++;
        }
    }
    cout<<count;
    return 0;
}