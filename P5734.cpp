#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int q;
    cin>>q;
    string data1;
    cin>>data1;
    for(int i=0;i<q;i++)
    {
        int oper;
        cin>>oper;
        if(oper==1)
        {
            string add;
            cin>>add;
            data1=data1+add;
            cout<<data1<<endl;
        }
        else if(oper==2)
        {
            int a,b;
            cin>>a>>b;
            int x=a+b;
            if(x>data1.size())
            {
                x=data1.size();
            }
            string temp(data1.begin()+a,data1.begin()+x);
            data1=temp;
            cout<<data1<<endl;
        }
        else if(oper==3)
        {
            int x;
            cin>>x;
            string temp;
            cin>>temp;
            data1.insert(x,temp);
            cout<<data1<<endl;
        }
        else
        {
            string data2;
            cin>>data2;
            int index1=0;
        
            bool find=false;
            int ans=-1;
            while(index1+data2.size()<=data1.size())
            {
                bool find=true;
                for(int j=0;j<data2.size();j++)
                {
                    if(data1[index1+j]!=data2[j])
                    {
                        find=false;
                        break;
                    }
                }
                if(find)
                {
                    ans=index1;
                    break;
                }
                index1++;
            }
            cout<<ans<<endl;
        }
    }
    //cout<<endl;
    return 0;
}
/*
6
aaaaa aaaaa  aaaaa aaaaa aaa
4 aaaaaaaa
1 aaaaa
4 b
2 2 3
3 0 fafafafa
4 fafa
*/