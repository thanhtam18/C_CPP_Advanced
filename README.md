# C Advanced

## Macro
### 1. #ifndef và #endif
- Là các chỉ thị tiền xử lý thường được sử dụng trong các file header để tránh định nghĩa file header (#include) nhiều lần trong cùng một file chính gây xung đột.
```C
#ifndef _HEADER_H
#define _HEADER_H
// do something
#endif
```
### 2. #define
- Được xử lý bởi preprocessor
- Thay thế đoạn code được khai báo macro vào bất cứ chỗ nào xuất hiện macro đó
- VD: #define SUM(a,b) (a+b). Preprocessor khi gặp bất kỳ lời gọi SUM(first+last) nào thì thay ngay bằng (first+last)
```C
#include <stdio.h>

void printError(const char *message) {
    printf("Error: %s\n", message);
}

void printWarning(const char *message) {
    printf("Warning: %s\n", message);
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
```
## Compile
Quy trình dịch là quá trình chuyển đổi từ ngôn ngữ bậc cao (NNBC) (C/C++, Pascal, Java, C#…) sang ngôn ngữ đích (ngôn ngữ máy) để máy tính có thể hiểu và thực thi. Ngôn ngữ lập trình C là một ngôn ngữ dạng biên dịch. Chương trình được viết bằng C muốn chạy được trên máy tính phải trải qua một quá trình biên dịch để chuyển đổi từ dạng mã nguồn sang chương trình dạng mã thực thi. Quá trình được chia ra làm 4 giai đoạn chính:

- Giai đoàn tiền xử lý (Pre-processor)
- Giai đoạn dịch NNBC sang Asembly (Compiler)
- Giai đoạn dịch asembly sang ngôn ngữ máy (Asember)
- Giai đoạn liên kết (Linker)
![image](https://github.com/thanhtam18/C_CPP_Advanced/assets/140053842/ef85d971-2194-4b50-b389-623df3593cc9)
 ### 1. Giai đoạn tiền xử lý – Preprocessor
Giai đoạn này sẽ thực hiện:
- Nhận mã nguồn
- Xóa bỏ tất cả chú thích, comments của chương trình
- Chỉ thị tiền xử lý (bắt đầu bằng #) cũng được xử lý
Ví dụ: chỉ thị #include cho phép ghép thêm mã chương trình của một tệp tiêu để vào mã nguồn cần dịch. Các hằng số được định nghĩa bằng #define sẽ được thay thế bằng giá trị cụ thể tại mỗi nơi sử dụng trong chương trình.
### 2. Cộng đoạn dịch Ngôn Ngữ Bậc Cao sang Assembly
- Phân tích cú pháp (syntax) của mã nguồn NNBC
- Chuyển chúng sang dạng mã Assembly là một ngôn ngữ bậc thấp (hợp ngữ) gần với tập lệnh của bộ vi xử lý.
### 3. Công đoạn dịch Assembly
- Dịch chương trình => Sang mã máy 0 và 1
- Một tệp mã máy (.obj) sinh ra trong hệ thống sau đó.
### 4. Giai đoạn Linker
- Trong giai đoạn này mã máy của một chương trình dịch từ nhiều nguồn (file .c hoặc file thư viện .lib) được liên kết lại với nhau để tạo thành chương trình đích duy nhất
- Mã máy của các hàm thư viện gọi trong chương trình cũng được đưa vào chương trình cuối trong giai đoạn này. Chính vì vậy mà các lỗi liên quan đến việc gọi hàm hay sử dụng biến tổng thể mà không tồn tại sẽ bị phát hiện. Kể cả lỗi viết chương trình chính không có hàm main() cũng được phát hiện trong liên kết. Kết thúc quá trình tất cả các đối tượng được liên kết lại với nhau thành một chương trình có thể thực thi được (executable hay .exe) thống nhất.
```C
Preprocessor
gcc -E main.c -o main.i

Complier
gcc -S main.i -o main.s

Assembler
gcc -c main.s -o main.o

Linker
gcc main.o -o main
```
## Library stdard and assert
### 1. stdarg Library
Thư viện stdarg.h trong C định nghĩa một kiểu biến va_list và 3 macro mà có thể được sử dụng để lấy các tham số trong một hàm khi số lượng tham số có thể biến đổi.
- va_start(va_list ap, last_arg): Macro này khởi tạo biến ap để được sử dụng với hai macro là va_arg và va_end. Tham số last_arg, là tham số cố định được biết cuối cùng, đang được truyền tới hàm
- va_arg(va_list ap, type): Macro này thu nhận tham số tiếp theo trong danh sách tham số của hàm với kiểu type
- va_end(va_list ap): Macro này cho phép một hàm có số tham số biến đổi mà sử dụng macro là va_start để trả về. Nếu va_end không được gọi trước khi trả về từ hàm đó, thì kết quả là không được định nghĩa
```C
#include "stdio.h"
#include "stdarg.h"

typedef struct{
    int x;
    int y;
}Point;

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
    getPoint(2,(Point){3,5},(Point){1,4});
    return 0;
}
```
### 2. assert Library
Thư viện assert.h trong C cung cấp một macro gọi là assert có thể được sử dụng để kiểm tra một giả định được tạo bởi chương trình. Nếu giả định này là false thì sẽ dừng chương trình in một thông báo chẩn đoán tìm lỗi.
```C
#include "stdio.h"
//#define NDEBUG // có thể tắt chức năng của assert
#include "assert.h"
#define LOG(condition, cmd) assert(condition && #cmd)

int main(int argc, char const *argv[])
{
    int a = 5;
    printf("a = %d\r\n", a);
    a = 7;
    assert(a < 6);
    printf("a = %d\r\n", a);
    return 0;
}
```
## Pointer
Trong ngôn ngữ C/C++, con trỏ (pointer) là những biến lưu trữ địa chỉ bộ nhớ của những biến khác.
### 1. Function Pointer
Con trỏ hàm là một biến lưu trữ địa chỉ của một hàm, thông qua biến đó, ta có thể gọi hàm mà nó trỏ tới. Con trỏ hàm thường được sử dụng khi có các hàm có cùng kiểu trả về và danh sách tham số, hoặc khi cần truyền một hàm cho hàm khác.
- Cú pháp : `<kiểu trả về> (*<tên con trỏ>)(<danh sách tham số>);`
```C
#include "stdio.h"

typedef enum{
    COMPARE,
    SUM
}Type;

void compare(int a, int b){
    (a > b) ? printf("a lớn hơn b\r\n") : printf("a nhỏ hơn b\r\n"); 
}

void sum(int a, int b){
    printf("Tong a va b = %d\r\n", a+b);
}

void function(void (*functionPointer)(int, int), Type type){
    switch(type){
        case COMPARE:
            functionPointer(3,4);
            break;
        case SUM:
            functionPointer(1,2);
            break;
    }
}

int main(int argc, char const *argv[])
{
    function(compare, COMPARE);
    function(sum, SUM);
    return 0;
}
```
### 2. Void Pointer
Con trỏ hàm là một con trỏ đặc biệt. Nó có thể lưu địa chỉ của mọi loại biến hoặc hàm. Nếu muốn lấy giá trị tại địa chỉ đó phải thực hiện ép kiểu dữ liệu.
```C
#include "stdio.h"

int sum(int a, int b){
    return a+b;
}

int main(int argc, char const *argv[])
{
    char *string = "Hello World";
    void *arr[] = {sum, string};
    printf("%s\r\n", (char*)arr[1]);
    printf("%d\r\n", ((int(*)(int, int))(arr[0]))(2,3));
    return 0;
}
```
### 3. NULL Pointer
- Con trỏ NULL là con trỏ lưu địa chỉ 0x00000000. Tức địa chỉ bộ nhớ 0, có ý nghĩa đặc biệt, cho biết con trỏ không trỏ vào đâu cả.
- Khi khai báo con trỏ nhưng chưa sử dụng thì phải gán NULL để tránh những lỗi không lường trước.
- Ví dụ `int *ptr = NULL`
### 4. Pointer to Pointer
Pointer to pointer là một loại con trỏ dùng để lưu trữ địa chỉ của biến con trỏ.
```C
#include "stdio.h"

int main(int argc, char const *argv[])	{

	int value = 100;
	int *ptr = &value;
	int **ptp = &ptr;

	printf("%p",ptp); //print address of ptr
	printf("%p", *ptp); //print address which hold by ptr
	printf("%d",**ptp); //print value at address which hold by ptr

	return 0;
}
```
### Size of Pointer
Kích thước của mọi con trỏ là như nhau. Kích thước này phụ thuộc vào môi trường hệ thống máy tính:
- Môi trường Windows 32 bit: 4 bytes
- Môi trường Windows 64 bit: 8 bytes

