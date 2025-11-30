#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<char>datas(n);
    for (int i = 0; i < n; i++)
    {
        cin >> datas[i];
    }
    int count = 0;
    vector<bool>uses(n, false);
    char pre = datas[0];
    for (int i = 1; i < n; i++)
    {
        if (pre == 'V' && uses[i - 1] == false)
        {
            if (datas[i] == 'K' && uses[i] == false)
            {
                count++;
                uses[i - 1] = true;
                uses[i] = true;
            }
        }
        pre = datas[i];
    }
    pre = datas[0];
    for (int i = 1; i < n; i++)
    {
        if (uses[i] == false && uses[i - 1] == false)
        {
            if (!(datas[i-1]=='K'&&datas[i]=='V'))
            {
                count++;
                break;
            }
        }
        pre = datas[i];
    }
    cout << count;
    return 0;
}
/*
21
VKVKKVKVKVKVKVKVVVKKV
*/