#include "apartment_manager.h"

MemberNode* createMemberNode(Member member) {
    MemberNode* newNode = (MemberNode*)malloc(sizeof(MemberNode));
    newNode->data = member;
    newNode->next = NULL;
    return newNode;
}

void addMember(const char* filename, Member member){
    FILE *filePtr = fopen(filename, "a+");
    if (filePtr == NULL) {
        perror("File Error");
        return;
    }
    fprintf(filename, "%s,%s,%s,%s\n", member.uid, member.roomNumber, member.name, member.licensePlate);
    fclose(filePtr);
}