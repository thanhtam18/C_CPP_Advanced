#include <iostream>
using namespace std;
#include <student.hpp>
#include <menu.hpp>
#include <list>
#include <iomanip>


void test(list<SinhVien> &list){
    SinhVien sv("Trung", 23, (GioiTinh)0, 8, 9, 9);
    list.push_back(sv);
    SinhVien sv1("Trun", 19, (GioiTinh)0, 8, 6, 9);
    list.push_back(sv1);
    SinhVien sv2("Trung", 18, (GioiTinh)1, 7, 9, 9);
    list.push_back(sv2);
    SinhVien sv3("Trung1", 23, (GioiTinh)0, 8, 9, 9);
    list.push_back(sv3);
    SinhVien sv4("Trung", 25, (GioiTinh)0, 4, 3, 4);
    list.push_back(sv4);
}

int main(int argc, char const *argv[])
{
    int key;
    list<SinhVien> dataBaseStudent;
    test(dataBaseStudent);
    while(1){
        MENU("---- Quan ly sinh vien ----",
                "Them sinh vien", 
                "Sua sinh vien", 
                "Xoa sinh vien", 
                "Tim kiem sinh vien", 
                "Sap xep sinh vien",
                "Danh sach sinh vien",
                "Luu vao database",
                "Thoat");
        cout<<("Vui long chon: ");
        cin>>key;
        HANDLE_OPTION(key,
                    CASE_OPTION(1,addStudent,dataBaseStudent)
                    CASE_OPTION(2,editStudent,dataBaseStudent)
                    CASE_OPTION(3,removeStudent,dataBaseStudent)
                    CASE_OPTION(4,searchStudent,dataBaseStudent)
                    );
    }
    return 0;
}