#include <iostream>
#include <string>
using namespace std;
bool Equal(string data1, string data2)
{
    int n1 = data1.size();
    int n2 = data2.size();
    if (n1 != n2)
    {
        return false;
    }
    for (int i = 0; i < n1; i++)
    {
        if (data1[i] != data2[n1-1-i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string datas;
    cin >> datas;
    while (1)
    {
        int n = datas.size();
        int mid = n / 2;
        string data1(datas.begin(), datas.begin() + mid);
        string data2(datas.begin() + mid, datas.end());
        //cout << data1 << endl << data2 << endl;
        if (!Equal(data1, data2))
        {
            break;
        }
        datas = data1;
    }
    cout << datas.size();
    return 0;
}