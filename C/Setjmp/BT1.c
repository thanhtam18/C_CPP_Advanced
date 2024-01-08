#include "stdio.h"
#include "setjmp.h"

jmp_buf buf;
int exception_code;
char* error_code = NULL;

#define TRY if ((exception_code = setjmp(buf)) == 0) 
#define CATCH(x) else if (exception_code == (x)) 
#define THROW(x,c) error_code = c; longjmp(buf, (x));

double divide(int a, int b) {
    if (b == 0) {
        THROW(1, "Lỗi: Phép chia cho 0!"); 
    }
        THROW(2, "Lỗi: Những lỗi khác!");
    return (double)a / b;
}

int main(int argc, char const *argv[])
{
    double result = 0;
    TRY{
       result = divide(1,0);
    }
    CATCH(1) {
        printf("%s\n", error_code);
    }CATCH(2) {
        printf("%s\n", error_code);
    }

    return 0;
}

