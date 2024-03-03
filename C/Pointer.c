#include "stdio.h"

// typedef enum{
//     COMPARE,
//     SUM
// }Type;

// void compare(int a, int b){
//     (a > b) ? printf("a lớn hơn b\r\n") : printf("a nhỏ hơn b\r\n"); 
// }

// void sum(int a, int b){
//     printf("Tong a va b = %d\r\n", a+b);
// }

// void function(void (*functionPointer)(int, int), Type type){
//     switch(type){
//         case COMPARE:
//             functionPointer(3,4);
//             break;
//         case SUM:
//             functionPointer(1,2);
//             break;
//     }
// }

int sum(int a, int b){
    return a+b;
}

int main(int argc, char const *argv[])
{
    // function(compare, COMPARE);
    // function(sum, SUM);
    char *string = "Hello World";
    void *arr[] = {sum, string};
    
    
    printf("%s\r\n", (char*)arr[1]);
    printf("%d\r\n", ((int(*)(int, int))(arr[0]))(2,3));
    return 0;
}
