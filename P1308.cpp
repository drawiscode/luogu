#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string target;
    string data1;
    getline(cin,target);
    getline(cin,data1);
    vector<string>datas;
    string temp;
    for(int i=0;i<data1.size();i++)
    {
        if(data1[i]==' ')
        {
            datas.emplace_back(temp);
            temp="";
        }
        else if(data1[i]>='A'&&data1[i]<='Z')
        {
            int add='a'-'A';
            temp+=data1[i]+add;
        }
        else
        {
            temp+=data1[i];
        }
    }
    datas.emplace_back(temp);
    for(int i=0;i<target.size();i++)
    {
        if(target[i]>='A'&&target[i]<='Z')
        {
            int add='a'-'A';
            target[i]=target[i]+add;
        }
    }
    int count=0;
    int first=0;
    for(int i=0;i<datas.size();i++)
    {
        string data2=datas[i];
        if(data2.size()!=target.size())
        {
            continue;
        }
        else 
        {
            bool equal=true;
            for(int j=0;j<target.size();j++)
            {
                if(target[j]!=data2[j])
                {
                    equal=false;
                    break;
                }
            }
            if(equal)
            {
                if(count==0)
                {
                    for(int j=0;j<i;j++)
                    {
                        first+=datas[i].size();
                    }
                    first+=i;
                }
                count++;
            }
        }
    }
    if(count==0)
    {
        cout<<-1;
    }
    else 
    {
        cout<<count<<" "<<first<<endl;
    }
    return 0;
}
/*
To
to be or not to be is a question

to
Did the Ottoman Empire lose its power at that time
*/