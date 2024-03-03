#include <iostream>
#include <string>

using namespace std;

class DoiTuong{
    protected:
        string Ten;  // property
        int Id;
        int Tuoi;
    public:
        DoiTuong(){  // constructor
            static int sID = 100;
            Id = sID;
            sID++;
        }
        void setTen(string getTen);  // method
        void setTuoi(int getTuoi);
        void hienThi();
};

void DoiTuong :: setTen(string getTen){
    Ten = getTen;
}

void DoiTuong :: setTuoi(int getTuoi){
    Tuoi = getTuoi;
}

void DoiTuong :: hienThi(){
    cout<<"Ten: "<<Ten<<endl;
    cout<<"Tuoi: "<<Tuoi<<endl; 
    cout<<"Id: "<<Id<<endl;  
}

class HocSinh : public DoiTuong{
    private:
        int Lop;
        string Khoi;
    public:
        void setLop(int getLop){// method
            Lop = getLop;
        }  
        void setKhoi(string getKhoi){
            Khoi = getKhoi;
        }
        void hienThi(){    // override
            cout<<"Ten: "<<Ten<<endl;
            cout<<"Tuoi: "<<Tuoi<<endl; 
            cout<<"Id: "<<Id<<endl;
            cout<<"Lop: "<<Lop<<endl;
            cout<<"Khoi: "<<Khoi<<endl; 
        }
};

class SinhVien : public DoiTuong{
    private:
        string mssv;
        string Khoa;
    public:
        void setmssv(string getmssv){// method
            mssv = getmssv;
        }  
        void setKhoa(string getKhoa){
            Khoa = getKhoa;
        }
        void hienThi(){
            cout<<"Ten: "<<Ten<<endl;
            cout<<"Tuoi: "<<Tuoi<<endl; 
            cout<<"Id: "<<Id<<endl;
            cout<<"MSSV: "<<mssv<<endl;
            cout<<"Khoa: "<<Khoa<<endl; 
        }
};

int main(int argc, char const *argv[])
{
    DoiTuong dt1;
    dt1.setTen("Tam");
    dt1.setTuoi(23);
    dt1.hienThi();
    cout<<"-------------------"<<endl;
    HocSinh hs2;
    hs2.setTen("Tuan");
    hs2.setTuoi(20);
    hs2.setLop(12);
    hs2.setKhoi("B");
    hs2.hienThi();
    cout<<"-------------------"<<endl;
    SinhVien sv3;
    sv3.setTen("An");
    sv3.setTuoi(23);
    sv3.setmssv("DHDT15");
    sv3.setKhoa("B");
    sv3.hienThi();
    return 0;
}
