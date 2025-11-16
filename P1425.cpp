#include <iostream>
using namespace std;
int main()
{
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    int swimming_time= c*60 + d - a* 60 -b;
    printf("%d %d",swimming_time/60,swimming_time%60);
    return 0;
}