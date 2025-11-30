#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int>first_pile(k);
    vector<int>second_pile(n - k);
    for (int i = 0; i < k; i++)
    {
        cin >> first_pile[i];
    }
    for (int i = 0; i < n - k; i++)
    {
        cin >> second_pile[i];
    }

    vector<int>new_pile;
    int minindex = min(k, n - k);
    int leave;
    if (k > n - k)
    {
        leave = 1;
    }
    else
    {
        leave = 2;
    }
    int index = 0;
    while (index < minindex)
    {
        new_pile.emplace_back(first_pile[index]);
        new_pile.emplace_back(second_pile[index]);
        index++;
    }
    if (leave == 1)
    {
        for (int i = index; i < k; i++)
        {
            new_pile.emplace_back(first_pile[i]);
        }
    }
    else
    {
        for (int i = index; i < n - k; i++)
        {
            new_pile.emplace_back(second_pile[i]);
        }
    }

    for (int i = 0; i < new_pile.size(); i++)
    {
        cout << new_pile[i] << " ";
    }
    return 0;
}