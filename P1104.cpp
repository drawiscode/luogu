#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;
struct Student
{
    string name;
    tuple<int, int, int>birth;
    int index;
};
bool cmp(Student student1, Student student2)
{
    int year1 = get<0>(student1.birth);
    int year2 = get<0>(student2.birth);
    int month1 = get<1>(student1.birth);
    int month2 = get<1>(student2.birth);
    int day1 = get<2>(student1.birth);
    int day2 = get<2>(student2.birth);
    if (year1 < year2)
    {
        return true;
    }
    else if (year1 > year2)
    {
        return false;
    }
    else if (month1 < month2)
    {
        return true;
    }
    else if (month1 > month2)
    {
        return false;
    }
    else if (day1 < day2)
    {
        return true;
    }
    else if (day1 > day2)
    {
        return false;
    }
    else
    {
        return student1.index > student2.index;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<Student>students(n);
    for (int i = 0; i < n; i++)
    {
        string name;
        int year, month, day;
        cin >> name >> year >> month >> day;
        students[i].name = name;
        students[i].birth = make_tuple(year, month, day);
        students[i].index = i;
    }
    sort(students.begin(), students.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        cout << students[i].name << endl;
    }
    return 0;
}