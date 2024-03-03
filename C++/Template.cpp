#include <iostream>

using namespace std;

template<typename valA, typename valB>

valA tong(valA A, valB B){
    return (valA)A+B;
}

int main(int argc, char const *argv[])
{
    printf("%d\r\n",tong(2,3));
    printf("%f\r\n",tong(2.5,3));
    return 0;
}
