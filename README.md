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
## Memory Layout
![image](https://github.com/thanhtam18/C_CPP_Advanced/assets/140053842/1ebd4633-efe6-41ac-ae4d-da53fb5c5af6)
### 1. Text
- Quyền truy cập chỉ Read và nó chưa lệnh để thực thi nên tránh sửa đổi instruction.
- Chứa khai báo hằng số trong chương trình (.rodata)
### 2. Data
- Quyền truy cập là read-write.
- Chứa biến toàn cục hoặc biến static với giá trị khởi tạo khác không.
- Được giải phóng khi kết thúc chương trình.
### 3. Bss
- Quyền truy cập là read-write.
- Chứa biến toàn cục hoặc biến static với giá trị khởi tạo bằng không hoặc không khởi tạo.
- Được giải phóng khi kết thúc chương trình.
### 4. Stack
- Quyền truy cập là read-write.
- Được sử dụng cấp phát cho biến local, input parameter của hàm,…
- Sẽ được giải phóng khi ra khỏi block code/hàm
### 5. Heap
- Quyền truy cập là read-write.
- Được sử dụng để cấp phát bộ nhớ động như: Malloc, Calloc, …
- Sẽ được giải phóng khi gọi hàm free,…
### So sánh Stack và Heap
- Bộ nhớ Heap và bộ nhớ Stack bản chất đều cùng là vùng nhớ được tạo ra và lưu trữ trong RAM khi chương trình được thực thi.
- Bộ nhớ Stack được dùng để lưu trữ các biến cục bộ trong hàm, tham số truyền vào... Truy cập vào bộ nhớ này rất nhanh và được thực thi khi chương trình được biên dịch.
- Bộ nhớ Heap được dùng để lưu trữ vùng nhớ cho những biến con trỏ được cấp phát động bởi các hàm malloc - calloc - realloc (trong C)
#### Kích thước vùng nhớ
- Stack: kích thước của bộ nhớ Stack là cố định, tùy thuộc vào từng hệ điều hành, ví dụ hệ điều hành Windows là 1 MB, hệ điều hành Linux là 8 MB (lưu ý là con số có thể khác tùy thuộc vào kiến trúc hệ điều hành của bạn).
- Heap: kích thước của bộ nhớ Heap là không cố định, có thể tăng giảm do đó đáp ứng được nhu cầu lưu trữ dữ liệu của chương trình.
#### Đặc điểm vùng nhớ
- Stack: vùng nhớ Stack được quản lý bởi hệ điều hành, dữ liệu được lưu trong Stack sẽ tự động hủy khi hàm thực hiện xong công việc của mình.
- Heap: Vùng nhớ Heap được quản lý bởi lập trình viên (trong C hoặc C++), dữ liệu trong Heap sẽ không bị hủy khi hàm thực hiện xong, điều đó có nghĩa bạn phải tự tay hủy vùng nhớ bằng câu lệnh free (trong C), và delete hoặc delete [] (trong C++), nếu không sẽ xảy ra hiện tượng rò rỉ bộ nhớ. 
## Library
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
### 3. setjmp Library
- Thư viện setjmp.h trong C định nghĩa macro setjmp(), một hàm longjmp(), và một kiểu biến jmp_buf. 
- Macro setjmp và hàm longjmp được sử dụng cùng nhau chủ yếu khi xử lý lỗi hay xử lý ngoại lệ.
- Ví dụ sử dụng setjmp cho macro TRY - CATCH:
```C
#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
int exception_code;

#define TRY if ((exception_code = setjmp(buf)) == 0) 
#define CATCH(x) else if (exception_code == (x)) 
#define THROW(x) longjmp(buf, (x))

double divide(int a, int b) {
    if (b == 0) {   
        THROW(1); 
    }
    return (double)a / b;
}

int main() {
    int a = 10;
    int b = 0;
    double result = 0.0;
    TRY {
        result = divide(a, b);
        printf("Result: %f\n", result);
    } CATCH(1) {
        printf("Error: Divide by 0!\n");
    }
    return 0;
}
```
## Bit Mask
Bit mask là một chuỗi các bit được sử dụng để thực hiện các phép toán bitwise (AND, OR, XOR, NOT) để kiểm soát và thay đổi giá trị của các bit cụ thể trong một số nguyên.
- Ví dụ đặt bit thứ k lên 1: `x |= (1 << k);`
- Ví dụ đặt bit thứ k về 0: `x &= ~(1 << k);`
- Ứng dụng Bit Mask:
```C
#include <stdio.h>
#include <stdint.h>

#define GENDER        1 << 0  // Bit 0: Giới tính (0 = Nữ, 1 = Nam) 
#define TSHIRT        1 << 1  // Bit 1: Áo thun (0 = Không, 1 = Có)
#define HAT           1 << 2  // Bit 2: Nón (0 = Không, 1 = Có)
#define SHOES         1 << 3  // Bit 3: Giày (0 = Không, 1 = Có)

void enableFeature(uint8_t *features, uint8_t feature) {
    *features |= feature;
}

void disableFeature(uint8_t *features, uint8_t feature) {
    *features &= ~feature;
}

int isFeatureEnabled(uint8_t features, uint8_t feature) {
    return (features & feature) != 0;
}

void listSelectedFeatures(uint8_t features) {
    printf("Selected Features:\n");
    if (features & GENDER) {
        printf("- Gender\n");
    }
    if (features & TSHIRT) {
        printf("- T-Shirt\n");
    }
    if (features & HAT) {
        printf("- Hat\n");
    }
    if (features & SHOES) {
        printf("- Shoes\n");
    }
}

void removeFeatures(uint8_t *features, uint8_t unwantedFeatures) {
    *features &= ~unwantedFeatures;
}

int main() {
    uint8_t options = 0;
    enableFeature(&options, GENDER | TSHIRT | HAT);
    removeFeatures(&options, TSHIRT);
    listSelectedFeatures(options); 
    return 0;
}
```
## Pointer
Trong ngôn ngữ C/C++, con trỏ (pointer) là những biến lưu trữ địa chỉ bộ nhớ của những biến khác.
![image](https://github.com/thanhtam18/C_CPP_Advanced/assets/140053842/a60a0442-1a11-4051-b3fa-7b7b53109ca9)
### 1. Function Pointer
Con trỏ hàm là một biến lưu trữ địa chỉ của một hàm, thông qua biến đó, ta có thể gọi hàm mà nó trỏ tới. Con trỏ hàm thường được sử dụng khi có các hàm có cùng kiểu trả về và danh sách tham số, hoặc khi cần truyền một hàm cho hàm khác.
- Syntax: `<kiểu trả về> (*<tên con trỏ>)(<danh sách tham số>);`
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
## Data Type
### 1. Extern
Khi khai báo một biến hoặc hàm kèm với từ khóa extern thì có nghĩa là chúng đã được khai báo ở một file khác và muốn sử dụng chúng ở file hiện tại.
- Syntax: `extern <kiểu dữ liệu> <tên biến hoặc hàm>`
### 2. Static
Syntax: `static <kiểu dữ liệu> <tên biến hoặc hàm>`
#### A. Global Static
Biến toàn cục static sẽ chỉ có thể được truy cập và sử dụng trong File khai báo nó, các File khác không có cách nào truy cập được. 
#### B. Local Static
Khi 1 biến cục bộ được khai báo với từ khóa static. Biến sẽ chỉ được khởi tạo 1 lần duy nhất và tồn tại suốt thời gian chạy chương trình, giá trị của nó không bị mất đi ngay cả khi kết thúc hàm. Biến cục bộ static chỉ có thể được gọi trong nội bộ hàm khởi tạo ra nó. Mỗi lần hàm được gọi, giá trị của biến chính bằng giá trị tại lần gần nhất hàm được gọi.
### 3. Register
- Sau khi khai báo một biến thì biến đó sẽ được lưu trong RAM, khi thực hiện một phép tính thì các biến đó sẽ được gửi đến Register và tiếp tục từ Register gửi đến bộ xử lí ALU để thực hiện phép tính. Kết quả của phép tính sẽ được gửi từ ALU đến Register và tiếp tục từ Register gửi trở lại RAM.
- Biến được khai báo với từ khóa register thì biến đó sẽ được lưu trực tiếp ở Register nên sẽ giảm bớt quá trình thực hiện phép tính chính vì thế nó sẽ giúp tăng hiệu năng của chương trình.
- Syntax: `register <kiểu dữ liệu> <tên biến>`
```C
#include <stdio.h>
#include <time.h>

int main() {
    clock_t startTime = clock();
    register int i;
    for (i = 0; i < 2000000; ++i) {}
    clock_t endTime = clock();
    double timeTaken = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
    printf("Thoi gian chay cua chuong trinh: %f\n", timeTaken);
    return 0;
}
```
### 4. Volatile
- Khai báo biến volatile là rất cần thiết để tránh những lỗi sai khó phát hiện do tính năng optimization của compiler. Từ khóa volatile được sử dụng để cho biết cho trình biên dịch rằng một biến hoặc vị trí bộ nhớ cụ thể có thể được thay đổi bên ngoài sự kiểm soát của chương trình.
- Kiểu dữ liệu volatile thường được sử dụng trong trường hợp biến khai báo được sử dụng để cập nhật giá trị từ bên ngoài như đọc giá trị cảm biến, khi đó chúng ta cần cập nhật giá trị của biến một cách liên tục.
```C
volatile int count;

// hàm ngắt có thể thay đổi biến count bất cứ lúc nào 
void ISR() {
  count++;
}

int main() {
  while (1) {
   // do something
  }
return 0;
}
```
