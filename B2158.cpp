#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node
{
    long long int no; 
    double grade;
};
bool cmp(Node student1,Node student2)
{
    int grade1=student1.grade;
    int grade2=student1.grade;
    return grade1>grade2;
}
int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<Node>students;
    for(int i=1;i<=n;i++)
    {
        int num1;
        double grade1;
        cin>>num1>>grade1;
        Node node;
        node.no=num1;
        node.grade=grade1;
        students.emplace_back(node);
    }
    sort(students.begin(),students.end(),cmp);
    cout<<students[k-1].no<<" "<<students[k-1].grade;
    return 0;
}