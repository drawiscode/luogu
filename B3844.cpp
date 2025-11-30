#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char start = 'A';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x = start - 'A' + j;
            x = x % 26;
            cout << (char)('A'+x);
        }
        cout << endl;
        if (start == 'Z')
        {
            start = 'A';
        }
        else
        {
            start++;
        }
    }
    return 0;
}