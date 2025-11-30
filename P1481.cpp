#include <vector>
#include <iostream>
#include <string>
using namespace std;
struct Node
{
    bool word_end;
    vector<Node*>next;
    Node()
    {
        word_end = false;
        next.resize(26);
        for (int i = 0; i < 26; i++)
        {
            next[i] = NULL;
        }
    }
};

void Insert(Node* curnode, string word)
{
    if (curnode == NULL)
    {
        curnode = new Node;
    }
    if (curnode->next[word[0] - 'a'] == NULL)
    {
        curnode->next[word[0] - 'a'] = new Node;
    }
    string nextstr(word.begin() + 1, word.end());
    if (nextstr.size() == 0)
    {
        curnode->next[word[0] - 'a']->word_end = true;
        return;
    }
    else
    {
        Insert(curnode->next[word[0] - 'a'], nextstr);
        return;
    }
}

int Height(Node* root1)
{
    if (root1 == NULL)
    {
        return 0;
    }
    else
    {
        int maxans = 0;
        for (int i = 0; i < 26; i++)
        {
            maxans = max(maxans, Height(root1->next[i]));
        }
        if (root1->word_end == true)
        {
            return maxans + 1;
        }
        else
        {
            return maxans;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    Node* root=new Node;
    for (int i = 0; i < n; i++)
    {
        string word;
        cin >> word;
        Insert(root, word);
    }

    int ans = Height(root);

    cout << ans;
    return 0;
}