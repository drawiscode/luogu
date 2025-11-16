#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(string s1, string s2)
{
    if (s1.size() > s2.size())
    {
        return false;
    }
    else if (s1.size() < s2.size())
    {
        return true;
    }
    else
    {
        int i = 0;
        while (i != s1.size())
        {
            if (s1[i] > s2[i])
            {
                return false;
            }
            else if (s1[i] < s2[i])
            {
                return true;
            }
            i++;
        }
        return false;
    }
}
int main()
{
    int n;
    cin >> n;
    string ans;
    int anscount = 1;
    cin >> ans;
    for (int i = 2; i <= n; i++)
    {
        string s;
        cin >> s;
        if (cmp(ans, s) == true)
        {
            ans = s;
            anscount = i;
        }
    }
    cout << anscount << endl << ans;
    return 0;
}