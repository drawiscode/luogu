#include <iostream>
#include <string>
using namespace std;
struct Node
{
    char name;
    Node*left;
    Node*right;
    Node(char n):name(n),left(NULL),right(NULL){}
};
/*
ABEDFCHG pre
CBADEFGH in

AEFDBHGC
*/
Node *Build_Tree(string preorder,string inorder)
{
    if(inorder.size()==0)
    {
        return NULL;
    }
    else
    {
        Node *root=new Node(inorder[0]);

        char target=inorder[0];
        int index_target;
        for(int i=0;i<preorder.size();i++)
        {
            if(preorder[i]==target)
            {
                index_target=i;
            }
        }
        string left_preorder(preorder.begin(),preorder.begin()+index_target);
        string right_preorder(preorder.begin()+1+index_target,preorder.end());

        string left_inorder(inorder.begin()+1,inorder.begin()+1+left_preorder.size());
        string right_inorder(inorder.begin()+1+left_preorder.size(),inorder.end());
        root->left=Build_Tree(left_preorder,left_inorder);
        root->right=Build_Tree(right_preorder,right_inorder);
        return root;
    }
}

void After_Order(Node*root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        After_Order(root->left);
        After_Order(root->right);
        cout<<root->name;
    }
}
int main()
{
    string preorder;
    string inorder;
    cin>>preorder>>inorder;
    Node* root=Build_Tree(preorder,inorder);
    
    After_Order(root);
    return 0;
}