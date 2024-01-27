/*
    File:   main.h
    Author: Thanh Tam
    Date:   19/1/2024
    Description: 
*/
#ifndef _MAIN_H
#define _MAIN_H

#define PRINT_ITEM(number, item) printf("%d. %s\r\n", number, item)

#define CASE_OPTION(number, function) case number: function(); break;

#define MENU(...)\
    do{\
        const char *items[] = {__VA_ARGS__};\
        int size = sizeof(items)/sizeof(items[0]);\
        printf("%s\r\n",items[0]);\
        for(int i = 1; i<size; i++){ \
            PRINT_ITEM(i, items[i]); \
        } \
    }while(0)

#define HANDLE_OPTION(option, ...) \
    switch (option){ \
        __VA_ARGS__ \
        case 0: return 0;\
    default: printf("Invalid option\r\n"); break; \
    }


typedef enum{
    UID,
    LICENSE_PLATE
}Type;

void _add();
void _edit();
void _delete();
void _search();

#endif