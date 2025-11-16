#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int x;
    int y;
    int len_x;
    int len_y;
};
int main()
{
    int n;
    cin>>n;
    vector<Node>nodes(n);
    for(int i=0;i<n;i++)
    {
        cin>>nodes[i].x>>nodes[i].y>>nodes[i].len_x>>nodes[i].len_y;
    }
    int targetx,targety;
    cin>>targetx>>targety;
    int ans=-1;
    for(int i=0;i<n;i++)
    {
        if((targetx>=nodes[i].x)&&(targetx<=nodes[i].x+nodes[i].len_x)&&(targety>=nodes[i].y)&&(targety<=nodes[i].y+nodes[i].len_y))
        {
            ans=i+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}