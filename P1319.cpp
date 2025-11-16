#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<vector<char>>data(n, vector<char>(n));
    int count = 0;
    int is_zero = true;
    int i = 0;
    int j = 0;
    while (count < n * n)
    {
        int cur_count;
        cin >> cur_count;
        count += cur_count;
        if (is_zero == true)
        {
            while (cur_count != 0)
            {
                data[i][j] = '0';
                cur_count--;
                j++;
                if (j == n)
                {
                    j = 0;
                    i++;
                }
            }
            is_zero = false;
        }
        else
        {
            while (cur_count != 0)
            {
                data[i][j] = '1';
                cur_count--;
                j++;
                if (j == n)
                {
                    j = 0;
                    i++;
                }
            }
            is_zero = true;
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << data[i][j];
        }
        cout << endl;
    }
    return 0;
}