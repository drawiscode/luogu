#include <iostream>
#include <vector>
using namespace std;
vector<int>trees;
int main()
{
    int n, m;
    cin >> n >> m;
    trees.resize(n + 1, 2);
    int plant = 0;
    int destroy = 0;
    for (int i = 0; i < m; i++)
    {
        int operators;
        int left;
        int right;
        cin >> operators >> left >> right;
        if (operators == 0)
        {
            for (int j = left; j <= right; j++)
            {
                if (trees[j] == 1)
                {
                    destroy++;
                }
                trees[j] = 0;
            }
        }
        else
        {
            for (int j = left; j <= right; j++)
            {
                if (trees[j] == 0)
                {
                    plant++;
                    trees[j] = 1;
                }
            }
        }
    }
    cout << plant - destroy << endl << destroy;
    return 0;
}