#include <iostream>
#include <string>

using namespace std;

class DoiTuong{
    public:
        virtual char *noiDung(){
            return (char*)"Hello World";
        }
        void hienThi(){
            cout<<noiDung()<<endl;
        }
};

class DoiTuong2 : public DoiTuong{
    public:
        virtual char *noiDung(){
            return (char*)"Hello Embedded World";
        }
};

int main(int argc, char const *argv[])
{
    DoiTuong dt1;
    dt1.hienThi();
    DoiTuong2 dt2;
    dt2.hienThi();
    return 0;
}
