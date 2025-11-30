#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool check(string data)
{
    int i = 0;
    while (i != data.size())
    {
        if (data[i] == 'E')
        {
            return true;
        }
        i++;
    }
    return false;
}
int main()
{
    vector<string>data_sum;
    while (1)
    {
        string temp;
        cin >> temp;
        data_sum.emplace_back(temp);
        if (check(temp))
        {
            break;
        }
    }
    string data;
    int i = 0;
    while (i != data_sum.size() - 1)
    {
        data += data_sum[i];
        i++;
    }
    int index = 0;
    int n = data_sum.size() - 1;
    while (data_sum[n][index] != 'E')
    {
        index++;
    }
    string end(data_sum[n].begin(), data_sum[n].begin() + index + 1);
    data += end;
    


    i = 0;
    int win = 0;
    int lose = 0;
    while (data[i] != 'E')
    {
        if (data[i] == 'W')
        {
            win++;
        }
        else if (data[i] == 'L')
        {
            lose++;
        }
        if (win >= 11 || lose >= 11)
        {
            if (win - lose >= 2 || lose - win >= 2)
            {
                printf("%d:%d\n", win, lose);
                win = 0;
                lose = 0;
            }
        }
        i++;
    }
    printf("%d:%d\n", win, lose);
    /*if (lose != 0 || win != 0)
    {
        printf("%d:%d\n", win, lose);
        win = 0;
        lose = 0;
    }*/
    printf("\n");
    win = 0;
    lose = 0;
    i = 0;

    while (data[i] != 'E')
    {
        if (data[i] == 'W')
        {
            win++;
        }
        else if (data[i] == 'L')
        {
            lose++;
        }
        if (win >= 21 || lose >= 21)
        {
            if (win - lose >= 2 || lose - win >= 2)
            {
                printf("%d:%d\n", win, lose);
                win = 0;
                lose = 0;
            }
        }
        i++;
    }
    printf("%d:%d\n", win, lose);
    /*if (lose != 0 || win != 0)
    {
        printf("%d:%d\n", win, lose);
        win = 0;
        lose = 0;
    }*/
    return 0;
}