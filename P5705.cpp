#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    printf("%s",s);
    return 0;
}