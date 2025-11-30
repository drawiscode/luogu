#include <iostream>
#include <string>
#include <vector>
using namespace std;
void Delete(string& str)
{
    int n = str.size();
    for (int i = 0; i < n; i++)
    {
        if (i == 0 && str[i] > str[i + 1])
        {
            str.erase(str.begin() + i);
            return;
        }
        else if (i== n - 1 && str[i] > str[i - 1])
        {
            str.erase(str.begin() + i);
            return;
        }
        else if (i != 0 && i != n - 1 && str[i] > str[i - 1] && str[i] > str[i + 1])
        {
            str.erase(str.begin() + i);
            return;
        }
    }
}
int main()
{

    string str;
    cin >> str;
    int k;
    cin >> k;
    int n = str.size();
    for (int i = 0; i < k; i++)
    {
        Delete(str);
    }
    int i = 0;
    while (str[i] == '0')
    {
        i++;
    }
    for (; i < str.size(); i++)
    {
        cout << str[i];
    }
    return 0;
}