#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int main()
{
    int n;
    cin >>n;
    priority_queue<int,vector<int>,greater<int>>p_q;
    for(int i=0;i<n;i++)
    {
        int node;
        scanf("%d",&node);
        p_q.push(node);
    }
    int sum = 0;
    int count=0;
    while(count!=n-1)
    {
        int t1=p_q.top();
        p_q.pop();
        int t2=p_q.top();
        p_q.pop();
        sum+=t1+t2;
        p_q.push(t1+t2);
        count++;
    }
    printf("%d",sum);
    return 0;
}