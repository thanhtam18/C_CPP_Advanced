#include <iostream>
#include <menu.h>

using namespace std;

int main(){
    int tableQuantity = 0;
    int key;
    while(1){
        MENU("---- Restaurant Manager ----",
                "Manager", 
                "Employer", 
                "Exit");
        cout<<("Your chose: ");
        cin>>key;
        HANDLE_OPTION(key,
                        CASE_OPTION(1,manager())
                        CASE_OPTION(2,employer())
        )
    }
}

