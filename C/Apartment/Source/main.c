#include "stdio.h"
#include "menu.h"
#include "apartment_manager.h"


int main(int argc, char const *argv[])
{
    int key;
    while(1){
        MENU("---- Apartment Manager ----","Add Member", "Edit Member", "Delete Member", "Search Member", "Exit");
        printf("Your choice: ");
        scanf("%d", &key);
        HANDLE_OPTION(key,
                    CASE_OPTION(1,_add)
                    CASE_OPTION(2,_edit)
                    CASE_OPTION(3,_delete)
                    CASE_OPTION(4,_search)
                    );
    }
    return 0;
}

