#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i = 1;
    while (1)
    {
        if (i * (1 + i) / 2 >= n)
        {
            break;
        }
        i++;
    }
    i--;
    int count = n - (i * (i + 1)) / 2;
    int sum = i + 2;
    i++;
    int line;
    int col;
    if (i % 2 == 0)
    {
        line = count;
        col = sum - line;
    }
    else
    {
        col = count;
        line = sum - col;
    }
    cout << line << "/" << col;
    return 0;
}