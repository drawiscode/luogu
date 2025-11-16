#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node
{
    char c;
    Node* left;
    Node* right;
    Node() :left(NULL), right(NULL) { ; }
    Node(char c1) :c(c1), left(NULL), right(NULL) { ; }
};
vector<Node*>nodes;
void PreOrder(Node* root)
{
    if (root == NULL)
    {
        return;
    }
 
    cout << root->c;
    PreOrder(root->left);
    PreOrder(root->right);
}
int main()
{
    int n;
    cin >> n;
    nodes.resize(26);
    for (int i = 0; i < 26; i++)
    {
        nodes[i] = new Node;
        nodes[i]->c = 'a' + i;
    }
    int root;
    for (int i = 0; i < n; i++)
    {
        string data;
        cin >> data;
        if (i == 0)
        {
            root = data[0] - 'a';
        }
        int j = 1;
        Node* node = nodes[data[0] - 'a'];
        char l = data[1];
        char r = data[2];
        if (l == '*')
        {
            node->left = NULL;
        }
        else
        {
            node->left = nodes[l - 'a'];
        }
        if (r == '*')
        {
            node->right = NULL;
        }
        else
        {
            node->right = nodes[r - 'a'];
        }
    }
    PreOrder(nodes[root]);
    return 0;
}