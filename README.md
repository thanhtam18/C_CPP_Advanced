<details>
<summary><h1>C Advanced</h1></summary>
	
<details>
<summary><h2>Macro</h2></summary>
	
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
</details>
<details>
<summary><h2>Compile</h2></summary>
	
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
### 2. Giai đoạn dịch Ngôn Ngữ Bậc Cao sang Assembly
- Phân tích cú pháp (syntax) của mã nguồn NNBC
- Chuyển chúng sang dạng mã Assembly là một ngôn ngữ bậc thấp (hợp ngữ) gần với tập lệnh của bộ vi xử lý.
### 3. Giai đoạn dịch Assembly
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
</details>
<details>
<summary><h2>Memory Layout</h2></summary>

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
</details>
<details>
<summary><h2>Library</h2></summary>
	
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
</details>
<details>
<summary><h2>Bit Mask</h2></summary>

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
</details>
<details>
<summary><h2>Pointer</h2></summary>

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
</details>
<details>
<summary><h2>Data Type</h2></summary>

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
</details>
<details>
<summary><h2>Struct and Union</h2></summary>

### 1. Struct
- Trong ngôn ngữ lập trình C, struct là một cấu trúc dữ liệu cho phép lập trình viên tự định nghĩa một kiểu dữ liệu mới bằng cách nhóm các biến có các kiểu dữ liệu khác nhau lại với nhau. struct cho phép tạo ra một thực thể dữ liệu lớn hơn và có tổ chức hơn từ các thành viên (members) của nó.
- Dữ liệu của các thành viên của struct được lưu trữ ở những vùng nhớ khác nhau. Do đó kích thước của 1 struct tối thiểu bằng kích thước các thành viên cộng lại tại vì còn phụ thuộc vào bộ nhớ đệm (struct padding).
![image](https://github.com/thanhtam18/C_CPP_Advanced/assets/140053842/04575700-69b8-4694-bedb-2b34f622742d)
![image](https://github.com/thanhtam18/C_CPP_Advanced/assets/140053842/bb355a6d-05b7-4e12-bafc-44061c5730d6)
### 2. Union
- Trong ngôn ngữ lập trình C, union là một cấu trúc dữ liệu giúp lập trình viên kết hợp nhiều kiểu dữ liệu khác nhau vào cùng một vùng nhớ.
- Mục đích chính của union là tiết kiệm bộ nhớ bằng cách chia sẻ cùng một vùng nhớ cho các thành viên của nó. Điều này có nghĩa là, trong một thời điểm, chỉ một thành viên của union có thể được sử dụng. Điều này được ứng dụng nhằm tiết kiệm bộ nhớ.
- Dữ liệu các thành viên sẽ dùng chung 1 vùng nhớ. Kích thước của union được tính là kích thước lớn nhất của kiểu dữ liệu trong union. Việc thay đổi nội dung của 1 thành viên sẽ dẫn đến thay đổi nội dung của các thành viên khác.
![image](https://github.com/thanhtam18/C_CPP_Advanced/assets/140053842/df55a724-bcb3-4398-8c98-7d38f3c3abd6)
![image](https://github.com/thanhtam18/C_CPP_Advanced/assets/140053842/12909923-ed9a-4600-b18c-2a5c4cedfb21)
![image](https://github.com/thanhtam18/C_CPP_Advanced/assets/140053842/29316ff5-6c8b-403c-90da-71ace0d9fe6f)
</details>
</details>
<details>
<summary><h1>C++ Advanced</h1></summary>
	
<details>
<summary><h2>Class</h2></summary>

### Declaring Object
Trong C++, từ khóa "class" được sử dụng để định nghĩa một lớp, là một cấu trúc dữ liệu tự định nghĩa có thể chứa dữ liệu và các hàm thành viên liên quan. 
```C++
class ClassName {
private:
    // Các thành phần riêng tư (private) chỉ có thể truy cập bên trong lớp
    // Dữ liệu thành viên, hàm thành viên, ...
protected:
    // Các thành phần bảo vệ (protected) tương tự như private, nhưng có thể truy cập từ lớp kế thừa
public:
    // Các thành phần công khai (public) được truy cập từ bên ngoài lớp
    // Dữ liệu thành viên, hàm thành viên, ...
    // Hàm thành viên và các phương thức khác có thể được định nghĩa tại đây
    // ...
};
```
### Constructor
Constructor trong C++ là một method sẽ được tự động gọi khi khởi tạo object. Constructor sẽ có tên trùng với tên của class.
```C++
class HinhChuNhat {
public:
    double chieuDai;
    double chieuRong;

    HinhChuNhat(){
        chieuDai = 10;
        chieuRong = 9;
    }

    double tinhDienTich() {
        return chieuDai * chieuRong;
    }
};
```
### Destructor
Destructor trong C++ là một method sẽ được tự động gọi khi object được giải phóng. Destructor sẽ có tên trùng với tên của class và thêm ký tự ~ ở phía trước tên.
```C++
class HinhChuNhat {
public:
    double chieuDai;
    double chieuRong;
    HinhChuNhat(){
        chieuDai = 10;
        chieuRong = 9;
    }
    ~HinhChuNhat(){
        std::cout << "Destructor " << '\n';
    }

    double tinhDienTich() {
        return chieuDai * chieuRong;
    }
};
```
### Static keyword
Khi một property trong class được khai báo với từ khóa static, thì tất cả các object sẽ dùng chung địa chỉ của property này.
Khi một method trong class được khai báo với từ khóa static:
- Method này độc lập với bất kỳ đối tượng nào của lớp.
- Method này có thể được gọi ngay cả khi không có đối tượng nào của class tồn tại.
- Method này có thể được truy cập bằng cách sử dụng tên class thông qua toán tử :: .
- Method này có thể truy cập các static property và các static method bên trong hoặc bên ngoài class.
- Method có phạm vi bên trong class và không thể truy cập con trỏ đối tượng hiện tại.
```C++
#include <iostream>

using namespace std;

class HinhChuNhat
{
public:
    double chieuDai;
    double chieuRong;
    static int count;

    HinhChuNhat(int dai = 5, int rong = 4);
    ~HinhChuNhat();

    double tinhDienTich();
    static void display();
};

HinhChuNhat::HinhChuNhat(int dai, int rong)
{
    chieuDai = dai;
    chieuRong = rong;
    count++;
}

HinhChuNhat::~HinhChuNhat()
{
    cout << "Destructor" << endl;
}

void HinhChuNhat::display()
{
    cout << "Number of object: " << count << endl;
}

int HinhChuNhat::count = 0;

int main()
{ 
    HinhChuNhat::display();

    return 0;
}
```
</details>
<details>
<summary><h2>Standard template library</h2></summary>
	
Standard Template Library ( STL) là một thư viện trong ngôn ngữ lập trình C++ cung cấp một tập hợp các template classes và functions để thực hiện nhiều loại cấu trúc dữ liệu và các thuật toán phổ biến. STL đã trở thành một phần quan trọng của ngôn ngữ C++ và làm cho việc lập trình trở nên mạnh mẽ, linh hoạt và hiệu quả.
### Container
#### Vector
Vector là một trong những container quan trọng nhất trong STL của C++. Nó cung cấp một mảng động với khả năng thay đổi kích thước một cách linh hoạt.

Một số đặc điểm chính của vector:
- vector là một mảng động, tức là có khả năng thay đổi kích thước một cách linh hoạt.
- Truy cập ngẫu nhiên: Việc truy cập các phần tử của vector có thể được thực hiện bằng cách sử dụng chỉ số.
- Hiệu suất chèn và xóa: Chèn và xóa phần tử ở cuối vector có hiệu suất tốt. Tuy nhiên, chèn và xóa ở vị trí bất kỳ có thể đòi hỏi di chuyển một số phần tử.
- 
Một số method của vector:
- at(): Truy cập vào phần tử của vector
- size(): Trả về kích thước của vector
- resize(): Thay đổi kích thước của vector
- begin(): Địa chỉ của phần tử đầu tiên của vector
- end(): Địa chỉ của phần tử cuối cùng của vector
- push_back(): Thêm phần tử vào vị trí cuối của vector
```C++
#include <iostream>
#include <vector>

using namespace std;

int main()
{
  
    vector <int> arr1 = {2,5,7,4,9};
    arr1.at(0) = 3;
    arr1.resize(7);

    for (int i = 0; i < arr1.size(); i++)
    {
        cout << "Value: " << arr1.at(i) << endl;
    }
    
    arr1.push_back(10);

    cout << "-----------" << endl;
    for (int i = 0; i < arr1.size(); i++)
    {
        cout << "Value: " << arr1.at(i) << endl;
    }
    return 0;
}
```
#### List
List là một container trong STL của C++, triển khai dưới dạng danh sách liên kết hai chiều. Dưới đây là một số đặc điểm quan trọng của list:
- Truy cập tuần tự: Truy cập các phần tử của list chỉ có thể thực hiện tuần tự, không hỗ trợ truy cập ngẫu nhiên.
- Hiệu suất chèn và xóa: Chèn và xóa ở bất kỳ vị trí nào trong danh sách có hiệu suất tốt hơn so với vector. Điều này đặc biệt đúng khi thêm/xóa ở giữa danh sách.

Một số method của list:
- push_back():
- pop_back():
- insert(): Chèn một node vào list
- erase(): Xóa một node của list
- size(): Trả về kích thước của list
```C++
#include <iostream>
#include <list>

using namespace std;

int main()
{
    list <int> arr1 = {2,5,7,4,9};
    list <int> :: iterator it;
    int i = 0;
    for (it = arr1.begin(); it != arr1.end(); ++it)
    {
        if (i == 2)
        {
            arr1.insert(it,10);
            break;
        }
        i++;
    }
    i = 0;
    for (it = arr1.begin(); it != arr1.end(); ++it)
    {
        if (i == 4)
        {
            arr1.erase(it);
            break;
        }
        i++;
    }

    for (auto const var : arr1)
    {
        cout << "Value: " << var << endl;
    }
    return 0;
}
```
#### Map
Map là một container trong STL của C++, cung cấp một cấu trúc dữ liệu ánh xạ key-value
- Map lưu trữ các phần tử dưới dạng cặp key-value, trong đó mỗi key phải là duy nhất trong map.
- Ta có thể thêm phần tử mới vào map bằng cách sử dụng operator [] hoặc hàm insert(). Để xóa phần tử, bạn có thể sử dụng hàm erase().
- Ta có thể sử dụng iterator để duyệt qua các phần tử của map
```C++
#include <map>
#include <iostream>
#include <string>

using namespace std;

int main() {
    map<string, int> myMap;

    map<string,int> ::iterator it;

    myMap["one"] = 1;
    myMap["two"] = 2;
    myMap["three"] = 3;
    myMap.insert(make_pair("four", 4));
    myMap.erase("one");

    for (auto const var : myMap)
    {
        cout << "Key: " << var.first << " , " << "Value: " << var.second << endl;
    }

    for (it = myMap.begin(); it != myMap.end(); ++it)
    {
        cout << "Key: " << (*it).first << " , " << "Value: " << (*it).second << endl;
    }
    return 0;
}
```
#### Array
Array là một container có kích thước cố định và có sẵn trong thư viện STL (Standard Template Library)
- array có kích thước cố định được xác định tại thời điểm biên dịch và không thể thay đổi sau khi được khai báo.
- array hỗ trợ truy cập ngẫu nhiên vào các phần tử thông qua toán tử []
```C++
#include <iostream>
#include <array>

using namespace std;

int main()
{
    array <int, 5> arr = {2,3,1,7,6};
    if (arr.empty())
    {
        cout << "Array is empty" << endl;
    }
    else
    {
        cout << "Array it not empty" << endl;
    }
    
    for (int i = 0; i < arr.size(); i++)
    {
        cout << "Value: " << arr.at(i) << endl;
    }
    return 0;
}
```
### Iterator
Iterator cung cấp một cách chung để duyệt qua các phần tử của một container mà không cần biết chi tiết về cách container được triển khai.
- Iterator là một đối tượng cho phép truy cập tuần tự qua các phần tử của một container.
- Nó giống như con trỏ, cho phép di chuyển qua các phần tử trong container.
```C++
#include <iostream>
#include <list>

using namespace std;

int main(int argc, char const *argv[])
{
    list<int> arr = {1,2,3,4,5};
    arr.push_back(7);
    for(list<int>::iterator it = arr.begin(); it != arr.end(); it++){
        if(*it == 2)
            arr.insert(it,44);
    }
    for(list<int>::iterator it = arr.begin(); it != arr.end(); it++){
        cout<<" "<<*it;
    }
    for(auto item : arr){
        cout<<" "<<item;
    }
    return 0;
}
```
### Algorithm
Thư viện STL (Standard Template Library) cung cấp một số thuật toán tiêu biểu thông qua algorithm. Các thuật toán này hoạt động trên các phạm vi hoặc các loại dữ liệu khác nhau, giúp thực hiện các nhiệm vụ như sắp xếp, tìm kiếm, chuyển đổi dữ liệu, và nhiều thao tác khác. 
```C++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    vector <int> arr = {3,5,7,4,1};

    for (auto const var : arr)
    {
        cout << "Vector: " << var << endl;
    }

    sort(arr.begin(), arr.end());
    
    cout << "vector after sort ascending: " << endl;

    for (auto const var : arr)
    {
        cout << "Vector: " << var << endl;
    }

    sort(arr.begin(), arr.end(), greater<int>());
    
    cout << "vector after sort descending: " << endl;

    for (auto const var : arr)
    {
        cout << "Vector: " << var << endl;
    }
    return 0;
}
```
</details>
<details>
<summary><h2>Generic Programming</h2></summary>

### Function template
Trong C++, function templates là một tính năng mạnh mẽ giúp viết các function hoặc class chung có thể được sử dụng cho nhiều kiểu dữ liệu khác nhau mà không cần phải triển khai nhiều phiên bản của cùng một function hoặc class. 
```C++
template <typename T>
T myFunction(T a, T b) {
    return a + b;
}

int result1 = myFunction(5, 10);       // Tự động suy luận T là int
double result2 = myFunction(3.14, 2.71);  // Tự động suy luận T là double
```
### Class template
Class templates trong C++ là một khái niệm tương tự như function templates, nhưng được áp dụng cho class thay vì function. Class templates cho phép bạn viết một lớp chung mà có thể được sử dụng với nhiều kiểu dữ liệu khác nhau.
```C++
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class MyContainer {
private:
    T element;

public:
    MyContainer(T val) : element(val) {}

    T getValue() const {
        return element;
    }
};

int main()
{
    MyContainer<int> intContainer(42);
    MyContainer<double> doubleContainer(3.14);
    MyContainer<string> stringContainer("Trung");

    int intValue = intContainer.getValue();
    double doubleValue = doubleContainer.getValue();
    string stringValue = stringContainer.getValue();

    cout << "int value: " << intValue << endl;
    cout << "double value: " << doubleValue << endl;
    cout << "string value: " << stringValue << endl;

    return 0;
}
```
### Advanced template techniques
#### Metaprogramming
Mục đích: Tính toán giai thừa tại thời điểm biên dịch.
```C++
#include <iostream>

template <unsigned int n>
struct Factorial {
 enum 
{ 
value = n * Factorial<n - 1>::value 
};
};

template <>
struct Factorial<0> {
 enum { value = 1 };
};

int main() {
 std::cout << "Factorial of 5 is " << Factorial<5>::value << std::endl;
 return 0;
}
```
#### Expression Templates
Thực hiện một phép cộng đơn giản giữa hai số nguyên:
```C++
#include <iostream>

template <typename A, typename B>
class AddExpr {
private:
	const A& a;
	const B& b;
public:
	AddExpr(const A& a, const B& b) : a(a), b(b) {}
	int eval() const {
		return a + b;
	}
};

template <typename A, typename B>
AddExpr<A, B> add(const A& a, const B& b) {
	return AddExpr<A, B>(a, b);
}

int main() {
	int x = 5,	y = 3;
	auto expr = add(x, y);
	std::cout << "Result: " << expr.eval() << std::endl; // Output: 8
	return 0;
}

```
#### Variadic Templates
Mục đích: Tạo một hàm có thể chấp nhận số lượng tham số đầu vào không xác định.
```C++
#include <iostream>

template <typename... Args>
void print(Args... args) {
 (std::cout << ... << args) << '\n';
}

int main() {
 print(1, 2, 3, "hello", 4.5, "Trung", 55);
 return 0;
}
```
</details>
<details>
<summary><h2>Smart Pointer</h2></summary>
	
Trong C++, smart pointers là một cơ chế quản lý bộ nhớ tự động giúp giảm thiểu rủi ro của lỗi liên quan đến quản lý bộ nhớ và giúp người lập trình tránh được việc quên giải phóng bộ nhớ đã được cấp phát.
### unique_ptr
unique_ptr là một loại smart pointer trong C++, giúp quản lý bộ nhớ động và tự động giải phóng bộ nhớ khi không còn cần thiết. 

Đặc điểm chính của unique_ptr là một unique_ptr chỉ có thể sở hữu một đối tượng hoặc mảng và khi một unique_ptr bị hủy, bộ nhớ của đối tượng sẽ được tự động giải phóng.
```C++
#include <iostream>
#include <memory>

using namespace std;

class HinhChuNhat {
private:
    int ChieuDai;
    int ChieuRong;
public:
    HinhChuNhat(int dai, int rong){
        ChieuDai = dai;
        ChieuRong = rong;
        cout << "Constructor called. "  << endl;
    }
    void tinhDienTich() {
        cout << "Dien tich: " << ChieuDai * ChieuRong << endl;
    }
    ~HinhChuNhat() {
        cout << "Destructor called " << endl;
    }
};
int main() {
    unique_ptr <HinhChuNhat> ptr1(new HinhChuNhat(10,5));
    (*ptr1).tinhDienTich();
    //unique_ptr <HinhChuNhat> ptr2(ptr1); // Khong cho phep
    unique_ptr <HinhChuNhat> ptr2 = move(ptr1); // gan object HinhChuNhat(10,5) cho ptr2, sau do remove ptr1
    (*ptr2).tinhDienTich();
    (*ptr1).tinhDienTich();

    return 0;
}
```
### shared_ptr
shared_ptr là một smart pointer khác trong C++ và cũng giúp quản lý bộ nhớ động. Điểm đặc biệt của shared_ptr là nó sử dụng một bộ đếm tham chiếu để theo dõi số lượng shared_ptr đang tham chiếu đến một đối tượng, và chỉ giải phóng bộ nhớ khi không còn shared_ptr nào tham chiếu đến nó.
```C++
#include <iostream>
#include <memory>

using namespace std;

class HinhChuNhat {
private:
    int ChieuDai;
    int ChieuRong;
public:
    HinhChuNhat(int dai, int rong){
        ChieuDai = dai;
        ChieuRong = rong;
        cout << "Constructor called. "  << endl;
    }
    void tinhDienTich() {
        cout << "Dien tich: " << ChieuDai * ChieuRong << endl;
    }
    ~HinhChuNhat() {
        cout << "Destructor called " << endl;
    }
};
int main() {
    shared_ptr <HinhChuNhat> ptr1 (new HinhChuNhat(40,10));
    (*ptr1).tinhDienTich();
    shared_ptr <HinhChuNhat> ptr2 (ptr1);
    shared_ptr <HinhChuNhat> ptr3;
    ptr3 = ptr2;
    (*ptr2).tinhDienTich();
    (*ptr1).tinhDienTich();
    (*ptr3).tinhDienTich();
    cout << "Count: " << ptr1.use_count() << endl;
    cout << "Count: " << ptr2.use_count() << endl;
    cout << "Count: " << ptr3.use_count() << endl;
    return 0;
}
```
### weak_ptr
weak_ptr là một cơ chế giữ tham chiếu yếu (weak reference) đến một đối tượng được quản lý bởi shared_ptr. Nó cung cấp một cách an toàn để theo dõi một đối tượng mà không tăng bộ đếm tham chiếu của shared_ptr. weak_ptr không trực tiếp truy cập đến đối tượng (object) mà nó theo dõi. 

weak_ptr có một phương thức là lock(), mà trả về một shared_ptr. Nếu shared_ptr mà weak_ptr theo dõi vẫn tồn tại, lock() sẽ trả về một shared_ptr hợp lệ có thể sử dụng để truy cập đối tượng. Ngược lại, nếu shared_ptr đã bị giải phóng, lock() sẽ trả về một shared_ptr rỗng.
```C++
#include <iostream>
#include <memory>

using namespace std;

class HinhChuNhat {
private:
    int ChieuDai;
    int ChieuRong;
public:
    HinhChuNhat(int dai, int rong){
        ChieuDai = dai;
        ChieuRong = rong;
        cout << "Constructor called. "  << endl;
    }
    void tinhDienTich() {
        cout << "Dien tich: " << ChieuDai * ChieuRong << endl;
    }

    ~HinhChuNhat() {
        cout << "Destructor called " << endl;
    }
};

int main() {

    shared_ptr <HinhChuNhat> ptr1 (new HinhChuNhat(40,10));
    shared_ptr <HinhChuNhat> ptr3(ptr1);
    weak_ptr <HinhChuNhat> ptr2;
    ptr2 = ptr1;
   
    ptr1.reset();
    ptr3.reset();
 
    if (auto ptr_lock = ptr2.lock())
    {
        ptr_lock->tinhDienTich();
    }
    else
    {
        cout << "Object has been deallocated" << endl;
    }
   
    cout << "Count: " <<ptr2.use_count() << endl;
    return 0;
}
```
</details>
<details>
<summary><h2>Lambda</h2></summary>
Lambda là một tính năng mạnh mẽ được thêm vào ngôn ngữ lập trình C++ từ phiên bản C++11. Lambda cho phép định nghĩa hàm ngắn gọn (anonymous function) mà không cần phải viết một hàm riêng biệt. Cú pháp của lambda rất linh hoạt và có thể được sử dụng để viết mã ngắn gọn và dễ đọc.
```C++
[capture](parameters) -> return_type {
    // function body
}
```
Capture: Cho phép bắt giữ biến từ môi trường xung quanh vào lambda.
- []: Không bắt giữ bất kỳ biến nào từ môi trường xung quanh.
- [var]: Bắt giữ biến var theo giá trị.
[&var]: Bắt giữ biến var theo tham chiếu.
- [=]: Bắt giữ tất cả biến theo giá trị.
- [&]: Bắt giữ tất cả biến theo tham chiếu.
Parameters (parameters): Tương tự như định nghĩa hàm, có thể bao gồm các tham số của lambda.
Return type (return_type): Kiểu dữ liệu trả về của lambda. Có thể bị bỏ qua nếu không cần.
Function body: Đặt trong dấu ngoặc nhọn {} và chứa mã nguồn thực thi của lambda.
```C++
#include <iostream>
#include <functional>
	
#define PI 3.14

using namespace std;
	
void processFunction(int a, int b, const function<void(int, int)>& func) {
    cout << "Processing numbers: " << a << " and " << b << endl;
    func(a, b);
}
int main() {
    int a = 10;
    const double g = 9.8;
    processFunction(7, 9, [a](int x, int y) {
        cout << "Product: " << x * y + a << endl;
    });
    processFunction(7, 9, [g](int x, int y) {
        cout << "Product: " << x + y + g << endl;
    });
    processFunction(7, 9, [](int x, int y) {
        cout << "Product: " << x - y + PI << endl;
    });
    return 0;
}
```
</details>
 
</details>
