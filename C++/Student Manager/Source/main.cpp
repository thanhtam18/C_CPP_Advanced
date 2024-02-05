#include <iostream>
#include <main.h>
#include <student.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int key;
    while(1){
        MENU("---- Quan ly sinh vien ----","Them sinh vien", "Sua sinh vien", 
                                            "Xoa sinh vien", "Tim kiem sinh vien", 
                                            "Sap xep sinh vien","Danh sach sinh vien",
                                            "Luu vao database","Thoat");
        cout<<("Vui long chon: ");
        cin>>key;
        // HANDLE_OPTION(key,

        //             );
    }
    return 0;
}

void addStudent(){

}