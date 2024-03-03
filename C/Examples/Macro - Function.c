#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

void test1(){
    printf("Ten: Nguyen Van A\n");
}

void test2(){
    printf("Gioi Tinh: Nam\n");
}

void test3(){
    printf("MSSV: 1001\n");
}

void test4(){
    printf("MSSV: 1001\n");
}

/* Macros are used to shorten the vehicle selection functions */ 
#define KEY_INPUT(func, ...)                                \
    /* Vehicle selection functions */                       \
    void func(void (*array[])()){                           \
        printf("Chuong trinh %s !!!\n", #func);             \
        int phim = 0;                                       \
        do                                                  \
        {                                                   \
            __VA_ARGS__                                     \
            printf("0: Exit\n");                            \
            printf("Enter your choice:");                    \
            scanf("%d", &phim);                             \
        } while (1);}                                       \

/* Macros are used to declare data in the vehicle selection functions */
#define KEY(key) key

#define NAME(name) name

#define VALUE(value) value

/* Macro used to display the data want to select in the vehicle selection functions */
#define DISPLAY(key, name)                                   \
    printf("%d: %s\n",key, name);                       

/* Macro used to check and display the data entered in the vehicle selection function */
#define IF(key, name)                                \
if (phim==key)                                               \
{                                                            \
    printf("Ban chon %s \n", name);                          \
    array[key-1]();                                            \
    break;                                                   \
}

/* Macros are used to combine displaying the data want to select, checking and displaying the entered data in the vehicle selection function */
#define KEY_VALUE(key, name)                                \
DISPLAY(key, name)                                           \
IF(key, name)

KEY_INPUT(Thong_tin_sinh_vien, 
        KEY_VALUE(
        KEY(1),
        NAME("Ten sinh vien")
    )
    KEY_VALUE(
        KEY(2),
        NAME("Gioi tinh")
    )
     KEY_VALUE(
        KEY(3),
        NAME("MSSV")
    ))

KEY_INPUT(Diem, 
        KEY_VALUE(
        KEY(1),
        NAME("Diem Toan")
    )
    KEY_VALUE(
        KEY(2),
        NAME("Diem Ly")
    )
     KEY_VALUE(
        KEY(3),
        NAME("Diem Hoa")
    )
    KEY_VALUE(
        KEY(4),
        NAME("Diem Anh Van")
    ))

int main(int argc, char const *argv[])
{

    void *func[]= {&test1, &test2, &test3};

    void *diem[]= {&test1, &test2, &test3, &test4};

    Thong_tin_sinh_vien(func);
    

    Diem(diem);
    
    return 0;
}
