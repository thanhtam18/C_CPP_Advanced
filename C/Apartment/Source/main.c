#include "stdio.h"
#include "apartment_manager.h"
#include "main.h"

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

void _add(){
    Member newMember;
    printf("---- Add New Member ----\r\n");
    printf("Enter User ID: ");
    scanf("%s",newMember.uId);
    printf("Enter Room Number: ");
    scanf("%s",newMember.roomNumber);
    printf("Enter Your Name: ");
    scanf("%s",newMember.name);
    printf("Enter License Plates: ");
    scanf("%s",newMember.licensePlate);
    addMember("10000_Members.csv",newMember);
}

void _delete(){
    char uId[20];
    printf("---- Delete Member ----\r\n");
    printf("Enter User ID: ");
    scanf("%s",uId);
    deleteMember("10000_Members.csv",uId);
}

void _edit(){
    Member updateMember;
    printf("---- Edit Member ----\r\n");
    printf("Enter User ID: ");
    scanf("%s",updateMember.uId);
    printf("Enter Room Number: ");
    scanf("%s",updateMember.roomNumber);
    printf("Enter Your Name: ");
    scanf("%s",updateMember.name);
    printf("Enter License Plates: ");
    scanf("%s",updateMember.licensePlate);
    editMember("10000_Members.csv",updateMember);
}

void _search(){
    int key;
    Type typeSearch;
    Member  result;
    printf("---- Search Member ----\r\n");
    printf("0. Search ID    1. Search licensePlate      Your choice: ");
    scanf("%d",&key);
    typeSearch = (Type)key;
    switch(typeSearch){
        case UID:
            char uid[20];
            printf("Enter User ID: ");
            scanf("%s",uid);
            result = searchMember("10000_Members.csv", uid, searchByUID);
            break;
        case LICENSE_PLATE:
            char licensePlate[20];
            int index;
            printf("Enter User License Plate: ");
            scanf("%s",licensePlate);
            while(licensePlate[index] != '\0')
                index++;
            licensePlate[index] = '\n';
            licensePlate[index+1] = '\0';
            result = searchMember("10000_Members.csv", licensePlate, searchByLicensePlate);
            break;
    }
    if(result.uId[0] == ' '){
        printf("ID does not exist\r\n");
    }
    else
        printf("uID: %s\tRoom Number: %s\tName: %s\tLicense Plates: %s", result.uId, result.roomNumber, result.name, result.licensePlate);
}