#include "stdio.h"
#include "apartment_manager.h"

typedef enum{
    UID,
    LICENSE_PLATE
}Type;

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

int main(int argc, char const *argv[])
{
    int key;
    while(1){
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
                _add();
                break;
            case 2:
                _edit();
                break;
            case 3:
                _delete();
                break;
            case 4:
                _search();
                break;
            default:
                return 0;
        }
    }
    return 0;
}
