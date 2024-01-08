#include "stdio.h"
#include "setjmp.h"

enum ErrorCodes { 
    NO_ERROR, 
    FILE_ERROR, 
    NETWORK_ERROR,
    CALCULATION_ERROR 
};

jmp_buf buf;
int exception_code;
char* error_message = NULL;

#define TRY if ((exception_code = setjmp(buf)) == 0) 
#define CATCH(x) else if (exception_code == (x)) 
#define THROW(x,c) error_message = c; longjmp(buf, (x)); 

void readFile() {
    printf("Đọc file...\n");
    THROW(FILE_ERROR, "Lỗi đọc file: File không tồn tại.");
}
void networkOperation() {
    printf("Hoạt động mạng...\n");
    THROW(NETWORK_ERROR, "Lỗi kết nối: Mạng không tìm thấy.");
}
void calculateData() {
    printf("Tính toán dữ liệu...\n");
    THROW(CALCULATION_ERROR, "Lỗi tính toán: Không có dữ liệu.");
}

int main(int argc, char const *argv[])
{
    TRY {
        readFile();
        networkOperation();
        calculateData();
    } 
    CATCH(FILE_ERROR) {
        printf("%s\n", error_message);
    }
    CATCH(NETWORK_ERROR) {
        printf("%s\n", error_message);
    }
    CATCH(CALCULATION_ERROR) {
        printf("%s\n", error_message);
    }



    return 0;
}