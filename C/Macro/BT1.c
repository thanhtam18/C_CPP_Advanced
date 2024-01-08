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

#define HANDLE_ERROR(condition, action, message)\
    if(condition)\
        action(message);\

int main() {
    int x = 11;
    HANDLE_ERROR(x == 10, printError, "x is not equal to 10");
    HANDLE_ERROR(x < 10, printWarning, "x is less than 10");
    HANDLE_ERROR(x > 10, printSuccess, "x is more than 10");
    return 0;
}