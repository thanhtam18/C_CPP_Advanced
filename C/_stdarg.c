#include "stdio.h"
#include "stdarg.h"

/*
va_arg(args, kiểu dữ liệu cần ép);
hàm trả về giá trị theo kiểu dữ liệu được ép và tự động tăng giá trị địa chỉ của con trỏ args lên 1 bước nhảy; 
*/

typedef struct{
    int x;
    int y;
}Point;

int sum(int quantity, ...){
    va_list args;
    va_start(args, quantity);
    int result = 0;
    for(int i = 0; i < quantity; i++){
        result += va_arg(args,int);
    }
    va_end(args);
    return result;
}

void getPoint(int quantity, ...){
    va_list args;
    va_start(args, quantity);
    for(int i = 0; i < quantity; i++){
        Point temp = va_arg(args,Point);
        printf("X: %d, Y: %d\r\n",temp.x,temp.y);
    }
    va_end(args);
}

int main(int argc, char const *argv[])
{
    printf("%d\r\n", sum(5,2,3,4,5,6));
    getPoint(2,(Point){3,5},(Point){1,4});
    return 0;
}
