// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

struct student{
    int id;
    string name;
    float gpa;
};

int main() {
    student array_of_student[10];
    for(int i=0; i<2; i++){
        cin>>array_of_student[i].id;
        cin>>array_of_student[i].name;
        cin>>array_of_student[i].gpa;
    }
    
    for(int i=0; i<2; i++){
        cout<<array_of_student[i].id<<" :: ";
        cout<<array_of_student[i].name<<" :: ";
        cout<<array_of_student[i].gpa<<endl;
    }
    return 0;
}