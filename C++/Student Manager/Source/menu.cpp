#include <menu.hpp>

void addStudent(list<SinhVien> &dataBase){
    string tenSV;
    int tuoiSV, gioiTinh;
    GioiTinh gioiTinhSV;
    float diemToan, diemLy, diemHoa;
    cout<<"------ Them Sinh Vien ------"<<endl;
    cout<<"Nhap Ten Sinh Vien: ";
    cin>>tenSV;
    do{
    cout<<"Nhap Tuoi Sinh Vien: ";
    cin>>tuoiSV;
    }while(tuoiSV < 0 || tuoiSV > 100);
    do{
    cout<<"Nhap Gioi Tinh Sinh Vien:  0.Nam   1.Nu     Ban Chon: ";
    cin>>gioiTinh;
    }while(gioiTinh != 0 && gioiTinh != 1);
    gioiTinhSV = (GioiTinh)gioiTinh;
    do{
    cout<<"Nhap Diem Toan: ";
    cin>>diemToan;
    }while(diemToan < 0 || diemToan > 10);
    do{
    cout<<"Nhap Diem Ly: ";
    cin>>diemLy;
    }while(diemLy < 0 || diemLy > 10);
    do{
    cout<<"Nhap Diem Hoa: ";
    cin>>diemHoa;      
    }while(diemHoa < 0 || diemHoa > 10);
    SinhVien sv(tenSV, tuoiSV, gioiTinhSV, diemToan, diemLy, diemHoa);
    dataBase.push_back(sv);
    cout<<"----------------------------"<<endl;
} 

void editStudent(list<SinhVien> &dataBase){
    cout<<"------ Sua Sinh Vien ------"<<endl;
    int mssv;
    cout<<"Nhap MSSV cua Sinh Vien muon sua: ";
    cin>>mssv;
    for(list<SinhVien>::iterator item = dataBase.begin(); item != dataBase.end(); item++){
        if(item->getMSSV() == mssv){
            string tenSV;
            int tuoiSV, gioiTinh;
            GioiTinh gioiTinhSV;
            float diemToan, diemLy, diemHoa;
            cout<<"Nhap Ten Sinh Vien: ";
            cin>>tenSV;
            do{
            cout<<"Nhap Tuoi Sinh Vien: ";
            cin>>tuoiSV;
            }while(tuoiSV < 0 || tuoiSV > 100);
            do{
            cout<<"Nhap Gioi Tinh Sinh Vien:  0.Nam   1.Nu    Ban Chon: ";
            cin>>gioiTinh;
            }while(gioiTinh != 0 && gioiTinh != 1);
            gioiTinhSV = (GioiTinh)gioiTinh;
            do{
            cout<<"Nhap Diem Toan: ";
            cin>>diemToan;
            }while(diemToan < 0 || diemToan > 10);
            do{
            cout<<"Nhap Diem Ly: ";
            cin>>diemLy;
            }while(diemLy < 0 || diemLy > 10);
            do{
            cout<<"Nhap Diem Hoa: ";
            cin>>diemHoa;      
            }while(diemHoa < 0 || diemHoa > 10);
            item->setTen(tenSV);
            item->setTuoi(tuoiSV);
            item->setGioiTinh(gioiTinhSV);
            item->setDiemToan(diemToan);
            item->setDiemLy(diemLy);
            item->setDiemHoa(diemHoa);
            cout<<"Sua thanh cong"<<endl;
            cout<<"----------------------------"<<endl;  
            return;
        }
    }
    cout<<"Sua that bai"<<endl;
    cout<<"----------------------------"<<endl;
}