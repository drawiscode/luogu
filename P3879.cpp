#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Node
{
    vector<Node*>next;
    vector<bool>articles;
    Node()
    {
        next.resize(26);
    }
};
void Insert(Node* root, string word, int article)
{
    if (root->next[word[0] - 'a'] == NULL)
    {
        root->next[word[0] - 'a'] = new Node;
        root->next[word[0] - 'a']->articles.resize(1001, false);
    }
    string nextword(word.begin() + 1, word.end());
    if (nextword.size() == 0)
    {
        root->next[word[0] - 'a']->articles[article] = true;
        return;
    }
    else
    {
        Insert(root->next[word[0] - 'a'], nextword, article);
    }
}

void Find(Node* root, string quere)
{
    string querenext(quere.begin() + 1, quere.end());
    if (querenext.size() == 0)
    {
        if (root->next[quere[0] - 'a'] == NULL)
        {
            cout << endl;
        }
        else
        {
            vector<int>ans;
            for (int i = 0; i < 1001; i++)
            {
                if (root->next[quere[0] - 'a']->articles[i])
                {
                    ans.emplace_back(i);
                }
            }
            for (int i = 0; i < ans.size() - 1; i++)
            {
                cout << ans[i] << " ";
            }
            cout << ans[ans.size() - 1] << endl;
        }
    }
    else
    {
        Find(root->next[quere[0] - 'a'], querenext);
    }
}

int main()
{
    int n;
    cin >> n;
    Node* root = new Node;
    root->articles.resize(1001, false);
    for (int i = 1; i <= n; i++)
    {
        int words;
        cin >> words;
        for (int j = 0; j < words; j++)
        {
            string word;
            cin >> word;
            Insert(root, word, i);
        }
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        string quere;
        cin >> quere;
        Find(root, quere);
    }
    return 0;
}