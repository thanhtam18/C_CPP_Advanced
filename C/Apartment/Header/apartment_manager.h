#ifndef _APARTMENT_H
#define _APARTMENT_H

#include "stdio.h"
#include "stdlib.h"

typedef struct {
char uid[20];
char roomNumber[10]; 
char name[50]; 
char licensePlate[20];
} Member;

typedef struct MemberNode {
Member data;
struct MemberNode* next;
} MemberNode;

MemberNode* createMemberNode(Member member);
void addMember(const char* filename, Member member);
void deleteMember(const char* filename, const char* uid);
void editMember(const char* filename, Member updatedMember);
int searchByUID(const Member* member, const char* uid);
int searchByLicensePlate(const Member* member, const char* licensePlate);
Member searchMember(const char* filename, const char* searchValue, int (*function)(const Member*, const char*));

#endif