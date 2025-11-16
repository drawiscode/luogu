#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int index;
    Node* left;
    Node* right;
    Node(int i) :index(i), left(NULL), right(NULL) {}
    Node() :index(-1), left(NULL), right(NULL) {}
};

vector<Node*>nodes;

int Depth(Node* root)
{
    if (root != NULL)
    {
        return 1 + max(Depth(root->left), Depth(root->right));
    }
    else
    {
        return 0;
    }
}
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i <= n; i++)
    {
        Node* node = new Node(i);
        nodes.emplace_back(node);
    }
    for (int i = 1; i <= n; i++)
    {
        int left;
        int right;
        scanf("%d%d", &left, &right);

        if (left != 0)
        {
            nodes[i]->left = nodes[left];
        }
        if (right != 0)
        {
            nodes[i]->right = nodes[right];
        }
    }
    int ans = Depth(nodes[1]);
    cout << ans;
    return 0;
}