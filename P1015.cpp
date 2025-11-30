#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Num
{
    vector<int>data;
    Num(int val)
    {
        while (val != 0)
        {
            data.emplace_back(val % 10);
            val /= 10;
        }
    }
    Num() { ; }
};
Num nums[31];
bool Judge(int index)
{
    int n = nums[index].data.size();
    for (int i = 0, j = n - 1; i <= j; i++, j--)
    {
        if (nums[index].data[i] != nums[index].data[j])
        {
            return false;
        }
    }
    return true;
}
void Add(int index, int N)
{
    vector<int>temp = nums[index - 1].data;
    reverse(temp.begin(), temp.end());
    nums[index].data.resize(temp.size() + 1, 0);
    for (int i = 0; i < temp.size(); i++)
    {
        nums[index].data[i] += nums[index - 1].data[i] + temp[i];
    }
    for (int i = 0; i < nums[index].data.size(); i++)
    {
        if (nums[index].data[i] >= N)
        {
            nums[index].data[i + 1] += nums[index].data[i] / N;
            nums[index].data[i] = nums[index].data[i] % N;
        }
    }
    
    int n = nums[index].data.size();
    int i = n - 1;
    while (nums[index].data[i] == 0)
    {
        i--;
    }
    nums[index].data.erase(nums[index].data.begin() + i + 1, nums[index].data.end());
}
void Print(int index)
{
    int n = nums[index].data.size();
    int i = n - 1;
    while (nums[index].data[i] == 0)
    {
        i--;
    }
    for (; i >= 0; i--)
    {
        cout << nums[index].data[i];
    }
    cout << endl;
    return;
}
int main()
{
    int N;
    int M;
    cin >> N;
    if (N == 16)
    {
        string data1;
        cin >> data1;
        int len = data1.size()-1;
        while (len >= 0)
        {
            int curnode;
            if (data1[len] >= '0' && data1[len] <= '9')
            {
                curnode = data1[len] - '0';
            }
            else if (data1[len] >= 'A' && data1[len] <= 'F')
            {
                curnode = data1[len] - 'A' + 10;
            }
            else if (data1[len] >= 'a' && data1[len] <= 'f')
            {
                curnode = data1[len] - 'a' + 10;
            }
            nums[0].data.emplace_back(curnode);
            len--;
        }
    }
    else
    {
        cin >> M;
        Num n1(M);
        nums[0].data = n1.data;
    }
    int count = 0;
    if (Judge(0))
    {
        cout << "STEP=" << count << endl;
        return 0;
    }
    //Print(0);

    while (count <= 30)
    {
        count++;
        Add(count, N);

      // Print(count);

        if (Judge(count))
        {
            cout << "STEP=" << count << endl;
            return 0;
        }
    }
    cout << "Impossible!" << endl;
    return 0;
}