#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int>datas(n);
    priority_queue<int,vector<int>,greater<int>>p_q;
    for(int i=0;i<n;i++)
    {
        int node;
        cin>>node;
        p_q.push(node);
    }
    int count=0;
    long long int ans=0;
    while(count!=n-1)
    {
        int add=0;
        add+=p_q.top();
        p_q.pop();
        add+=p_q.top();
        p_q.pop();
        ans+=add;
        p_q.push(add);
    }

    cout << ans;
    return 0;
}