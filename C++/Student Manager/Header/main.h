/*
    File:   main.h
    Author: Thanh Tam
    Date:   19/1/2024
    Description: This header file declare functions and macro for file main.cpp
*/
#ifndef _MAIN_H
#define _MAIN_H


#define PRINT_ITEM(number, item) cout << number <<". "<< item <<endl;

#define CASE_OPTION(number, function) case number: function(); break;

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

void addStudent();

#endif