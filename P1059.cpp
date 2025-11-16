#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int>data;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int node;
        cin >> node;
        data.emplace_back(node);
    }
    sort(data.begin(), data.end(), less<int>());
    int prenode = data[0];

    int count=1;
    for (int i = 1; i < n; i++)
    {
        if (data[i] != prenode)
        {
            count++;
            prenode = data[i];
        }
    }
    cout << count << endl;
    
    prenode = data[0];
    cout << prenode << " ";
    for (int i = 1; i < n; i++)
    {
        if (data[i] != prenode)
        {
            cout << data[i] << " ";
            prenode = data[i];
        }
    }
    return 0;
}