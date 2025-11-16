/*
5 4
1 3 10000 118014
1 1 1 1
2 3 10000
2 1 1
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    int n,q;
    cin>>n>>q;
    vector<unordered_map<int,int>>mps(n+1);
    for(int i=0;i<q;i++)
    {
        int oper;
        cin>>oper;
        if(oper==1)
        {
            int node;
            int gezi;
            int no;
            cin>>node>>gezi>>no;
            mps[node][gezi]=no;
        }
        else
        {
            int node;
            int gezi;
            cin>>node>>gezi;
            if(mps[node][gezi]==0)
            {
                cout<<0<<endl;
            }
            else
            {
                cout<<mps[node][gezi]<<endl;
            }
        }
    }
    return 0;
}