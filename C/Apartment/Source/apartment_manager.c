#include "apartment_manager.h"

/*
 Description: Creates a new MemberNode.
 Input: Struct Member
 Output: Address of new MemberNode
*/
MemberNode* createMemberNode(Member member) {
    MemberNode* newNode = (MemberNode*)malloc(sizeof(MemberNode));
    newNode->data = member;
    newNode->next = NULL;
    return newNode;
}

/*
 Description: Add a new data member into specified file.
 Input:
   - filename: The name of the file to add data.
   - member: Struct Member want to add
 Output: None
*/
void addMember(const char* filename, Member member){
    FILE *filePtr = fopen(filename, "a");
    if (filePtr == NULL) {
        printf("Can not open file\r\n");
        return;
    }
    fprintf(filePtr, "%s,%s,%s,%s\n", member.uId, member.roomNumber, member.name, member.licensePlate);
    fclose(filePtr);
    printf("---- Add successfully ----\r\n");
}

/*
 Description: Compare two string.
 Input:
   - item1: string firt.
   - item2: string second.
 Output: 
   - Return 0 if the two strings are the same.
   - Return -1 or 1 if the two strings are the difference.
*/
static int compare(const char *item1, const char *item2){
    while(*item1 && *item2 && *item1 == *item2){
        ++item1;
        ++item2;
    }
    return (int)(*item1) - (int)(*item2);
}

/*
 Description: Delete a member in the specified file.
 Input:
   - filename: The name of the file to delete data.
   - uid: string ID of memeber want to delete.
 Output: None.
*/
void deleteMember(const char* filename, const char* uid) {
    FILE* file = fopen(filename, "r");
    FILE* tempFile = fopen("temp.csv", "w");
    bool isDelete = false;
    if (file == NULL || tempFile == NULL) {
        printf("Can not open file\r\n");
        return;
    }
    char oneLine[104];
    Member memberData;
    while (fgets(oneLine, sizeof(oneLine), file) != NULL) {
        sscanf(oneLine, "%[^,],%[^,],%[^,],%[^,]", memberData.uId, memberData.roomNumber, memberData.name, memberData.licensePlate);
        if (compare(memberData.uId, uid) != 0) {
            fprintf(tempFile, "%s", oneLine);
        }
        else{
            isDelete = true;
        }
    }
    fclose(file);
    fclose(tempFile);
    remove(filename);
    rename("temp.csv", filename);
    (isDelete) ? printf("---- Delete successfully ----\r\n") : printf("---- ID does not exist ----\r\n"); 
}

/*
 Description: Edit a data member in the specified file.
 Input:
   - filename: The name of the file to edit data.
   - uid: string ID of memeber want to edit.
 Output: None
*/
void editMember(const char* filename, Member updatedMember) {
    FILE* file = fopen(filename, "r");
    FILE* tempFile = fopen("temp.csv", "w");
    bool isEdit = false;
    if (file == NULL || tempFile == NULL) {
        printf("Can not open file\r\n");
        return;
    }
    char oneLine[104];
    Member currentMember;
    while (fgets(oneLine, sizeof(oneLine), file)) {
        sscanf(oneLine, "%[^,],%[^,],%[^,],%[^,]", currentMember.uId, currentMember.roomNumber, currentMember.name, currentMember.licensePlate);
        if (compare(currentMember.uId, updatedMember.uId) == 0){
            fprintf(tempFile, "%s,%s,%s,%s\n",updatedMember.uId, updatedMember.roomNumber, updatedMember.name, updatedMember.licensePlate);
            isEdit = true;
        }
        else
            fprintf(tempFile, "%s", oneLine);
    }
    fclose(file);
    fclose(tempFile);
    remove(filename);
    rename("temp.csv", filename);
    (isEdit) ? printf("---- Edit successfully ----\r\n") : printf("---- ID does not exist ----\r\n");
}

/*
 Description: Compare ID member with search ID.
 Input:
   - member: Struct data member.
   - uid: ID of member want to search.
 Output: 
   - Returns 0 if the member ID and search ID are the same; 
   - Returns -1 or 1 if the member ID and search ID are the difference; 
*/
int searchByUID(const Member* member, const char* uid){
    return compare(member->uId, uid);
}

/*
 Description: Compare License Plate member with search License Plate.
 Input:
   - member: Struct data member.
   - licensePlate: License Plate of member want to search.
 Output: 
   - Returns 0 if the member License Plate and search License Plate are the same; 
   - Returns -1 or 1 if the member License Plate and search License Plate are the difference; 
*/
int searchByLicensePlate(const Member* member, const char* licensePlate){
    return compare(member->licensePlate, licensePlate);
}

/*
 Description: Search member with ID.
 Input:
   - filename: The name of the file to search data.
   - searchValue: ID or licensePlate of member want to search.
   - function: Function pointer to the search function
 Output: Result data member
*/
Member searchMember(const char* filename, const char* searchValue, int (*function)(const Member*, const char*)){
    FILE *file = fopen(filename, "r");
    Member result = {" ", " ", " ", " "};
    if (file == NULL) {
        printf("Can not open file\r\n");
        return result;
    }
    char oneLine[104];
    while (fgets(oneLine, sizeof(oneLine), file)) {
        Member currentMember;
        sscanf(oneLine, "%[^,],%[^,],%[^,],%[^,]", currentMember.uId, currentMember.roomNumber, currentMember.name, currentMember.licensePlate);
        if (function(&currentMember, searchValue) == 0) {
            result = currentMember;
            break;
        }
    }
    fclose(file);
    return result; 
}