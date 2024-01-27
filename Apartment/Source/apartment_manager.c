#include "apartment_manager.h"

MemberNode* createMemberNode(Member member) {
    MemberNode* newNode = (MemberNode*)malloc(sizeof(MemberNode));
    newNode->data = member;
    newNode->next = NULL;
    return newNode;
}

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

static int compare(const char *item1, const char *item2){
    while(*item1 && *item2 && *item1 == *item2){
        ++item1;
        ++item2;
    }
    return (int)(*item1) - (int)(*item2);
}

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

int searchByUID(const Member* member, const char* uid){
    return compare(member->uId, uid);
}

int searchByLicensePlate(const Member* member, const char* licensePlate){
    return compare(member->licensePlate, licensePlate);
}

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