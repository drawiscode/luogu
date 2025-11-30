#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>drawings;
vector<int>authors;
bool Judge()
{
    for (int i = 1; i < authors.size(); i++)
    {
        if (authors[i] == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    int m;
    cin >> n >> m;
    drawings.resize(n + 1);
    authors.resize(m + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> drawings[i];
    }
    int left = 1;
    int right = 1;
    int minlen = n+2;
    pair<int, int>ans;
    authors[drawings[right]]++;
    if (Judge())
    {
        cout << 1 << " " << 1;
        return 0;
    }
    while (1)
    {
        if (Judge())
        {
            if ((right - left + 1) < minlen)
            {
                minlen = right - left + 1;
                ans = make_pair(left, right);
            }
            authors[drawings[left]]--;
            left++;
        }
        else
        {
            right++;
            authors[drawings[right]]++;
            if (right == n)
            {
                bool have = false;
                while (Judge())
                {
                    have = true;
                    authors[drawings[left]]--;
                    left++;
                }
                if (have&&right - left + 2 < minlen)
                {
                    ans = make_pair(left - 1, right);
                }
                break;
            }
        }
    }
    cout << ans.first << " " << ans.second;
    return 0;
}