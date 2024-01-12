#include "stdio.h"
#include "apartment_manager.h"

void add(){
    Member newMember;
    printf("---- Add New Member ----\r\n");
    printf("Enter User ID: ");
    scanf("%s",newMember.uid);
    printf("Enter Room Number: ");
    scanf("%s",newMember.roomNumber);
    printf("Enter Your Name: ");
    scanf("%s",newMember.name);
    printf("Enter License Plates: ");
    scanf("%s",newMember.licensePlate);
    addMember("test.csv",newMember);
}

int main(int argc, char const *argv[])
{
    int key;
    printf("----Apartment Manager----\r\n");
    printf("1. Add Member\r\n");
    printf("2. Edit Member\r\n");
    printf("3. Delete Member\r\n");
    printf("4. Search Member\r\n");
    printf("0. Exit\r\n");
    printf("Enter Your Choice: ");
    scanf("%d",&key);
    switch(key){
        case 1:
            add();
            break;
    }
    return 0;
}
