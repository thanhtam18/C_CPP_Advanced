#include <stdio.h>

int main()
{
    int x = -121;
    int reversed = 0;
    for(int number = x; number != 0;){
        int digit = number % 10;
        reversed = reversed * 10 + digit;
        number /= 10;
    }
    if(reversed == x)
        printf("True");
    else
        printf("False");
    return 0;
}

