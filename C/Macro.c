#include <stdio.h>

void printError(const char *message) {
    printf("Error: %s\n", message);
}

void printWarning(const char *message) {
    printf("Warning: %s\n", message);
}

void printInfo(const char *message) {
    printf("Info: %s\n", message);
}

void printDebug(const char *message) {
    printf("Debug: %s\n", message);
}

void printCritical(const char *message) {
    printf("Critical: %s\n", message);
}

void printSuccess(const char *message) {
    printf("Success: %s\n", message);
}
/*Các ứng dụng của macro*/
#define HANDLE_ERROR(condition, action, message) do { \
    if(condition)\
        action(message);\
}while(0)

#define LOG(cmd) #cmd   //tham số truyền vào LOG sẽ biến thành chuỗi

#define DECLARE_VARIABLE(prefix, number) int prefix##number   

#define PRINT_ITEM(number, item) printf("%d. %s\r\n", number, item)

#define MENU(...)\
    do{\
        const char *items[] = {__VA_ARGS__};\
        int size = sizeof(items)/sizeof(items[0]);\
        for(int i = 0; i<size; i++){ \
            PRINT_ITEM(i+1, items[i]); \
        } \
    }while(0)

#define CASE_OPTION(number, function) case number: function(); break;

#define HANDLE_OPTION(option, ...) \
    switch (option){ \
        __VA_ARGS__ \
    default: printf("Invalid option\r\n"); break; \
    }

void feature1(){ printf("Feature 1 is selected\r\n");}
void feature2(){ printf("Feature 2 is selected\r\n");}
void feature3(){ printf("Feature 3 is selected\r\n");}
void feature4(){ printf("Feature 4 is selected\r\n");}

int main() {
    int x = 11;
    HANDLE_ERROR(x == 10, printError, "x is not equal to 10");
    HANDLE_ERROR(x < 10, printWarning, "x is less than 10");
    HANDLE_ERROR(x > 10, printSuccess, "x is more than 10");

    printf("%s\r\n",LOG(3753));

    DECLARE_VARIABLE(val, 1);   // dòng lệnh này tương ứng với int val1;
    DECLARE_VARIABLE(val, 2);   // dòng lệnh này tương ứng với int val2;
    val1 = 5;
    printf("%d\r\n",val1);

    MENU("Feature 1", "Feature 2", "Feature 3", "Feature 4", "Exit");
    int option;
    scanf("%d",&option);
    HANDLE_OPTION(option,
                CASE_OPTION(1,feature1)
                CASE_OPTION(2,feature2)
                CASE_OPTION(3,feature3)
                CASE_OPTION(4,feature4)
                );
    return 0;
}