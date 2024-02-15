#include <iostream>
using namespace std;
#include <student.hpp>
#include <menu.hpp>
#include <list>
#include <iomanip>


void test(list<Student> &list){
    Student sv("Trung", 23, (Gender)0, 8, 9, 9);
    list.push_back(sv);
    Student sv1("Trun", 19, (Gender)0, 8, 6, 9);
    list.push_back(sv1);
    Student sv2("Trung", 18, (Gender)1, 7, 9, 9);
    list.push_back(sv2);
    Student sv3("Trung1", 23, (Gender)0, 8, 9, 9);
    list.push_back(sv3);
    Student sv4("Trung", 25, (Gender)0, 4, 3, 4);
    list.push_back(sv4);
}

int main(int argc, char const *argv[])
{
    int key;
    list<Student> dataBaseStudent;
    test(dataBaseStudent);
    while(1){
        MENU("---- Student Manager ----",
                "Add Student", 
                "Edit Student", 
                "Remove Student", 
                "Search Student", 
                "Sort Student",
                "Display List Student",
                "Save to DataBase",
                "Exit");
        cout<<("Your chose: ");
        cin>>key;
        HANDLE_OPTION(key,
                    CASE_OPTION(1,addStudent,dataBaseStudent)
                    CASE_OPTION(2,editStudent,dataBaseStudent)
                    CASE_OPTION(3,removeStudent,dataBaseStudent)
                    CASE_OPTION(4,searchStudent,dataBaseStudent)
                    CASE_OPTION(5,sortStudent,dataBaseStudent)
                    CASE_OPTION(6,displayListStudent,dataBaseStudent)
                    CASE_OPTION(7,saveListStudent,dataBaseStudent)
                    );
    }
    return 0;
}