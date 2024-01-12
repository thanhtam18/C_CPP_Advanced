#include "apartment_manager.h"

MemberNode* createMemberNode(Member member) {
    MemberNode* newNode = (MemberNode*)malloc(sizeof(MemberNode));
    newNode->data = member;
    newNode->next = NULL;
    return newNode;
}

void addMember(const char* filename, Member member){
    FILE *filePtr = fopen(filename, "a+");
    fputs("\n",filePtr);
    fputs(member.uid,filePtr);
    fputs(",",filePtr);
    fputs(member.roomNumber,filePtr);
    fputs(",",filePtr);
    fputs(member.name,filePtr);
    fputs(",",filePtr);
    fputs(member.licensePlate,filePtr);
    fclose(filePtr);
}