#include <iostream>
#include <student.hpp>
#include <menu.hpp>
#include <list>
using namespace std;

int main(int argc, char const *argv[])
{
    int key;
    list<SinhVien> dataBaseStudent;
    while(1){
        MENU("---- Quan ly sinh vien ----","Them sinh vien", "Sua sinh vien", 
                                            "Xoa sinh vien", "Tim kiem sinh vien", 
                                            "Sap xep sinh vien","Danh sach sinh vien",
                                            "Luu vao database","Thoat");
        cout<<("Vui long chon: ");
        cin>>key;
        HANDLE_OPTION(key,
                    CASE_OPTION(1,addStudent,dataBaseStudent)
                    CASE_OPTION(2,editStudent,dataBaseStudent)
                    );
    }
    return 0;
}