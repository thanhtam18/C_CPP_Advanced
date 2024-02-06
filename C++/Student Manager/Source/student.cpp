#include <student.hpp>

void SinhVien :: setTen(string ten){
    this->tenSinhVien = ten;
}
void SinhVien :: setTuoi(int tuoi){
    this->tuoiSinhVien = tuoi;
}
void SinhVien :: setGioiTinh(GioiTinh gt){
    this->gioiTinhSinhVien = gt;
}
void SinhVien :: setDiemToan(float Toan){
    this->monToan = Toan;
}
void SinhVien :: setDiemLy(float Ly){
    this->monLy = Ly;
}
void SinhVien :: setDiemHoa(float Hoa){
    this->monHoa = Hoa;
}

string SinhVien :: getTenSV(){
    return tenSinhVien;
}
int SinhVien :: getTuoi(){
    return tuoiSinhVien;
}
GioiTinh SinhVien :: getGioiTinh(){
    return gioiTinhSinhVien;
}
int SinhVien :: getMSSV(){
    return maSoVinhVien;
}
float SinhVien :: getDiemToan(){
    return monToan;
}
float SinhVien :: getDiemLy(){
    return monLy;
}
float SinhVien :: getDiemHoa(){
    return monHoa;
}
float SinhVien :: getDiemTrungBinh(){
    return (monToan + monLy + monHoa)/3;
}
HocLuc SinhVien :: getHocLuc(){
    if(getDiemTrungBinh() >= 8)
        return GIOI;
    else if(getDiemTrungBinh() >= 7)
        return KHA;
    else if(getDiemTrungBinh() >= 5)
        return TRUNG_BINH;
    else
        return YEU;    
}