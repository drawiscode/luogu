#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int name;
    Node*left;
    Node*right;
    Node():left(NULL),right(NULL){}
    Node(int n):name(n),left(NULL),right(NULL){}
};
void PreOrder(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->name<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}
void InOrder(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    InOrder(root->left);
    cout<<root->name<<" ";
    InOrder(root->right);
}
void PostOrder(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->name<<" ";
}
vector<Node*>nodes;
int main()
{
    int n;
    cin>>n;
    nodes.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        nodes[i]=new Node;
        nodes[i]->name=i;      
    }
    for(int i=1;i<=n;i++)
    {
        int left;
        int right;
        cin>>left>>right;
        nodes[i]->left=nodes[left];
        nodes[i]->right=nodes[right];
    }
    PreOrder(nodes[1]);
    cout<<endl;
    InOrder(nodes[1]);
    cout<<endl;
    PostOrder(nodes[1]);
    return 0;
}