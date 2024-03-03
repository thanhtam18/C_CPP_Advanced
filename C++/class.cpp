#include <iostream>
#include <string>

using namespace std;

class sinhVien{
    public:
    sinhVien(string l_ten, int l_tuoi, string l_lop){     // contructor
        static int l_mssv = 1000;
        mssv = l_mssv;
        mssv++;
        ten = l_ten;
        tuoi = l_tuoi;
        lop = l_lop;
    }
    string ten; //property
    static int tuoi;
    string lop;
    int mssv;
    void display();  // method
    ~sinhVien(){  //destructor
        cout<<"Huy object co ten: "<<ten<<endl;
    }
};

int sinhVien::tuoi;

void sinhVien::display(){
    cout<<"Ten: "<<ten<<endl;
    cout<<"Tuoi: "<<tuoi<<endl;
    cout<<"MSSV: "<<mssv<<endl;
    cout<<"Lop: "<<lop<<endl;
}


int main(int argc, char const *argv[])
{
    sinhVien sv1("Tam", 22, "DKTD15C"), sv2("Tuan", 23, "CTD14");
    sv1.display();
    cout<<"-----------------"<<endl;
    sv2.display();
    return 0;
}
