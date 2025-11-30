#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    vector<string>data;
    string temp;
    cin >> temp;
    int n = temp.size();
    data.emplace_back(temp);
    for (int i = 1; i < n; i++)
    {
        string t;
        cin >> t;
        data.emplace_back(t);
    }
    vector<int>ans;
    int count = 0;
    int i = 0;
    int j = 0;
    bool is_zero = true;
    while (count < n * n)
    {
        int cur_count = 0;
    
        if (is_zero == true)
        {
            while (data[i][j] == '0')
            {
                cur_count++;
                j++;
                if (j == n)
                {
                    j = 0;
                    i++;
                    if (i == n)
                    {
                        break;
                    }
                }
            }
            is_zero = false;
        }
        else
        {
            while (data[i][j] == '1')
            {
                cur_count++;
                j++;
                if (j == n)
                {
                    j = 0;
                    i++;
                    if (i == n)
                    {
                        break;
                    }
                }
            }
            is_zero = true;
        }
        ans.emplace_back(cur_count);
        count += cur_count;
    }
    cout << n << " ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}