#include <iostream>

using namespace std;

class ToanHoc{
    private:
        int a;
        int b;
        int c;
    public:
        void tong(int A, int B){
            printf("%d\r\n", A+B);
        }
        void tong(int A, int B, int C){
            printf("%d\r\n",A+B+C);
        }
        void tong(int A, double B, int C){
            printf("%f\r\n",A+B+C);
        }
};


int main(int argc, char const *argv[])
{
    ToanHoc th;
    th.tong(1,2);
    th.tong(1,2,3);
    th.tong(1,2.5,3);
    return 0;
}
