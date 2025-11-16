#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;
struct Use_Imessage
{
    int room_id;
    int start_time;
    int during_time;
};
struct Node
{
    unordered_set<Use_Imessage>have_rooms;    
    int count;
    int count_suc;
    Node():count(0),count_suc(0){}
};
vector<bool>rooms_in_use;
vector<Node>students;
void Oper(int i)
{
    string oper;
    cin>>oper;
    if(oper=="reserve")
    {
        int student_ID;
        int room_ID;
        cin>>student_ID>>room_ID;
        string time;
        int hour;
        int minute;
        hour=(time[0]-'0')*10+(time[1]-'0');
        minute=(time[3]-'0')*10+(time[4]-'0');
        int sumtime=hour*60+minute;
        int during;
        cin>>during;

        Use_Imessage imessage;
        imessage.start_time=sumtime;
        imessage.during_time=during;
        imessage.room_id=room_ID;
        if(during>120)
        {
            cout<<"FAIL"<<endl;
            students[student_ID].count++;
            return;
        }
        //判断是否违规
        for(auto node:students[student_ID].have_rooms)
        {
            if(node.room_id==room_ID)
            {
                cout<<"FAIL"<<endl;
                students[student_ID].count++;
                return;
            }
            if(rooms_in_use[room_ID])
            {
                cout<<"FAIL"<<endl;
                students[student_ID].count++;
                return;
            }
            int start_time=node.start_time;
            int end_time=start_time+node.during_time;

            int time1=sumtime;
            int time2=time1+during;
            if(!((time2<start_time)||(time1>end_time)))
            {
                cout<<"FAIL"<<endl;
                students[student_ID].count++;
                return;
            }
        }
        students[student_ID].have_rooms.insert(imessage);
        return;
    }
    else
    {
        int num;
        cin>>num;
        return;
    }
}
int main()
{
    students.resize(1000);
    rooms_in_use.resize(1000);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        Oper(i);
    }
}