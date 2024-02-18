#include <iostream>
using namespace std;
#include <list>
#include <menu.hpp>
#include <food.hpp>
#include <manager.hpp>
#include <employer.hpp>

void testList(list<Food> *da){
    Food doAn[] = {{"banh mi",15000},
                    {"pepsi", 8000},
                    {"pho", 25000},
                    {"coca",10000},
                    {"hu tieu", 20000}};
    for (int i = 0; i < 5; i++){
        da->push_back(doAn[i]);
    } 
}

int main(){
    list<Food> dataBaseFood;
    testList(&dataBaseFood);
    int tableQuantity = 0;
    Manager mn(&dataBaseFood, &tableQuantity);
    int key;
    while(1){
        MENU("---- Restaurant Management ----",
                "Manager", 
                "Employer", 
                "Exit");
        cout<<("Your chose: ");
        cin>>key;
        HANDLE_OPTION(key,
                        CASE_OPTION(1,managerHandle,mn)
                        CASE_OPTION(2,employerHandle,mn)
        )
    }
}



