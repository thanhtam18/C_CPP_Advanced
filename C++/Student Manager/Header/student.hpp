/*
    File:   student.h
    Author: Thanh Tam
    Date:   19/1/2024
    Description: This header file declare functions and macro for file student.cpp
*/
#ifndef _STUDENT_H
#define _STUDENT_H

#include <iostream>
#include <string>

using namespace std;

typedef enum{
    NAM,
    NU
}GioiTinh;

typedef enum{
    GIOI,
    KHA,
    TRUNG_BINH,
    YEU
}HocLuc;

class SinhVien{
    private:
        float monToan;
        float monLy;
        float monHoa;
        int maSoVinhVien;
        string tenSinhVien;
        int tuoiSinhVien;
        GioiTinh gioiTinhSinhVien;
    public:
        SinhVien(string ten = "", int tuoi = 0, GioiTinh gioiTinh = NAM, float toan = 0, float ly = 0, float hoa = 0) : 
                 tenSinhVien(ten), tuoiSinhVien(tuoi), gioiTinhSinhVien(gioiTinh),
                 monToan(toan), monHoa(hoa), monLy(ly){
                    static int id = 1000;
                    maSoVinhVien = id;
                    id++;
                 };

        void setTen(string ten);
        void setTuoi(int tuoi);
        void setGioiTinh(GioiTinh gt);
        void setDiemToan(float Toan);
        void setDiemLy(float Ly);
        void setDiemHoa(float Hoa);

        string getTenSV();
        GioiTinh getGioiTinh();
        int getTuoi();
        int getMSSV();
        float getDiemToan();
        float getDiemLy();
        float getDiemHoa();
        float getDiemTrungBinh();
        HocLuc getHocLuc();
};

#endif