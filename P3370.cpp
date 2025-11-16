#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    int n;
    cin>>n;
    unordered_map<string,int>mp;
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        mp[str]++;
    }
    printf("%d",mp.size());
    return 0;
}