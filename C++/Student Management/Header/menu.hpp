/*
    File:   menu.hpp
    Author: Thanh Tam
    Date:   19/1/2024
    Description: This header file declare functions and macro for file menu.cpp
*/
#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "student.hpp"
#include <list>
#include <stdarg.h>
#include <iomanip>

using namespace std;

#define PRINT_ITEM(number, item) cout << number <<". "<< item <<endl;

#define CASE_OPTION(number, function, dataBase) case number: function(dataBase); break;

#define MENU(...)\
    do{\
        const char *items[] = {__VA_ARGS__};\
        int size = sizeof(items)/sizeof(items[0]);\
        cout<< items[0] <<endl;\
        for(int i = 1; i<size-1; i++){ \
            PRINT_ITEM(i, items[i]); \
        } \
        PRINT_ITEM(0, items[size-1]); \
    }while(0)

#define HANDLE_OPTION(option, ...) \
    switch (option){ \
        __VA_ARGS__ \
        case 0: return 0;\
    default: cout << "Invalid option" << endl; break; \
    }

#define SUB_MENU(...)\
    const char *items[] = {__VA_ARGS__};\
    int size = sizeof(items)/sizeof(items[0]);\
    for(int i = 0; i<size-1; i++){ \
        PRINT_ITEM(i+1, items[i]); \
    } \
    PRINT_ITEM(0, items[size-1]); 

typedef enum{
    STUDENT_NAME = 1,
    STUDENT_CODE
}SearchType;

typedef enum{
    NAME = 1,
    MATHS_SCORE,
    PHYSICS_SCORE,
    CHEMISTRY_SCORE,
    AVERAGE_SCORE
}SortType;

void addStudent(list<Student> &dataBase);
void editStudent(list<Student> &dataBase);
void removeStudent(list<Student> &dataBase);
void searchStudent(list<Student> &dataBase);
void sortStudent(list<Student> &dataBase);
void displayListStudent(list<Student> &dataBase);
void saveListStudent(list<Student> &dataBase);
#endif
