#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    //vector<bool>is_left(n + 1, false);
   // vector<bool>is_right(n + 1, false);
    unordered_set<int>is_left;
    unordered_set<int>is_right;
    vector<pair<int, int>>car_partings;
    vector<int>p(k + 1);
    for (int i = 0; i < k + 1; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 0; i < k; i++)
    {
        int left = p[i];
        int right = p[i + 1] - 1;
        is_left.insert(left);
        is_right.insert(right);
        car_partings.emplace_back(make_pair(left, right));
    }

    vector<int>sum(n + 1, 0);
    sum[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (is_left.find(i)!=is_left.end())
        {
            sum[i] = sum[i - 1] + 1;
        }
        else
        {
            sum[i] = sum[i - 1];
        }
    }

    int q;
    cin >> q;
    vector<pair<int, int>>queres(q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d%d", &queres[i].first, &queres[i].second);
    }


    for (int i = 0; i < q; i++)
    {
        int left = queres[i].first;
        int right = queres[i].second;
        if (left > right)
        {
            int temp = left;
            left = right;
            right = temp;
        }

        if (left == right)
        {
                printf("%d\n", 1);
        }
        else if (sum[right] == sum[left])
        {
            printf("%d\n", 2);
        }
        else
        {
            int thisans = sum[right] - sum[left] - 1;
            if (is_left.find(left)!=is_left.end())
            {
                thisans++;
            }
            if (is_right.find(right) != is_right.end())
            {
                thisans++;
            }
            printf("%d\n", thisans + 2);
        }
    }
    return 0;
}