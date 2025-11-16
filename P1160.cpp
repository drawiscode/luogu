#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int left;
    int right;
    Node():left(-1),right(-1){}
};
int main()
{
    int n;
    cin>>n;
    vector<Node>nodes(n+1);
    vector<bool>use(n+1,true);
    use[0]=false;
    for(int i=2;i<=n;i++)
    {
        int k;
        int right;
        cin>>k>>right;
        //use[i]=true;
        if(right==1)
        {
            // k i temp
            if(nodes[k].right==-1)
            {
                nodes[k].right=i;
                nodes[i].left=k;
            }
            else
            {
                int temp=nodes[k].right;
                nodes[k].right=i;
                nodes[i].left=k;
                nodes[i].right=temp;
                nodes[temp].left=i;
            }
        }
        else//temp i k
        {
            if(nodes[k].left==-1)
            {
                nodes[k].left=i;
                nodes[i].right=k;
            }
            else
            {
                int temp=nodes[k].left;
                nodes[k].left=i;
                nodes[i].right=k;
                nodes[i].left=temp;
                nodes[temp].right=i;
            }
        }
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        // a x 
        if(use[x]==false)
        {
            continue;
        }
        if(nodes[x].left!=-1&&nodes[x].right!=-1)
        {
            int a=nodes[x].left;
            int b=nodes[x].right;
            nodes[a].right=b;
            nodes[b].left=a;
            use[x]=false;
        }
        else if(nodes[x].left!=-1)//a x
        {
            int a=nodes[x].left;
            nodes[a].right=-1;
            use[a]=false;
        }
        else if(nodes[x].right!=-1)//x a
        {
            int a=nodes[x].right;
            nodes[a].left=-1;
            use[a]=false;
        }
        else
        {
            use[x]=false;
        }
    }
    
    int a;
    for(int i=1;i<=n;i++)
    {
        if(use[i]==true)
        {
            a=i;
            break;
        }
    }
    while(nodes[a].left!=-1)
    {
        a=nodes[a].left;
    }
    while(nodes[a].right!=-1)
    {
        cout<<a<<" ";
        a=nodes[a].right;
    }
    cout<<a;
    return 0;
}
/*
4
1 0
2 1
1 0
2
3
3
*/


/*

*/