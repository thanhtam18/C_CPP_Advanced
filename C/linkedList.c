#include "stdio.h"
#include "stdlib.h"

struct linkedList
{
    int data;
    struct linkedList *pNext;
};

typedef struct linkedList *node;


int length(node head)
{
    node pNode = head;
    int index = 0;
    while (pNode != NULL){
        index++;
        pNode = pNode->pNext;
   }
   return index;
}


node createNode(int value){
    node temp;
    temp = (node)malloc(sizeof(struct linkedList));
    temp->data = value;
    temp->pNext = NULL;
    return temp;
}

node pushBack(node head, int value){
    node temp, ptrNode;
    temp = createNode(value);
    if(head == NULL){
        head = temp;
    }
    else{
        ptrNode = head;
        while(ptrNode->pNext != NULL){
            ptrNode = ptrNode->pNext;
        }
        ptrNode->pNext = temp;
    }
    return head;
}

node pushFront(node head, int value){
    node temp;
    temp = createNode(value);
    temp->pNext = head;
    head = temp;
    return head;
}

node pushWithLocation(node head, int value, int location){
    if(location < 0 || location > (length(head) - 1)){
        printf("Vi tri them phan tu khong hop le");
        return head;
    }
    node temp, pNodeRight, pNode;
    pNode = head;
    temp = createNode(value);
    int i = 0;
    while(i != location || pNode != NULL){
        if(i == location - 1){
            temp->pNext = pNode->pNext;
            pNode->pNext = temp;
            break;
        }
        i++;
        pNode = pNode->pNext;
    }
    return head;
}

node input(){
    node nodeHead = NULL;
    int n, val;
    do{
        printf("Nhap so phan tu: ");
        scanf("%d",&n);
    }while(n<=0);
    for(int i = 0; i < n; i++){
        printf("Nhap gia tri: ");
        scanf("%d",&val);
        nodeHead = pushBack(nodeHead, val);
    }
    return nodeHead;
}

int get(node head, int index){
    int i = 0;
    node pNode = head;
    while(pNode != NULL & i != index){
        i++;
        pNode = pNode->pNext;
    }
    return pNode->data;
}


void printList(node head)
{
    node pNode = head;
    printf("\n[ ");
    while(pNode != NULL){        
        printf("( %d ) ",pNode->data);
        pNode = pNode->pNext;
    }
    printf(" ]");
}

node deleteList(node head, int location){
    if(location < 0 || location > (length(head) - 1)){
        printf("Vi tri xoa phan tu khong hop le");
        return head;
    }
    int i = 0;
    node pNode,temp;
    temp = head;
    while(i != location || temp != NULL){
        if(i == location - 1){
            pNode = temp;
        }
        else if(i == location){
            pNode->pNext = temp->pNext;
            free(temp);
            break;
        }
        i++;
        temp = temp->pNext;
    }
    return head;
}

int main(int argc, char const *argv[])
{
    node head = input();
    //head = pushFront(head,88);
    //head = pushBack(head, 45);
    //head = pushWithLocation(head,11,10);
    //head = deleteList(head,3);
    printList(head);
    return 0;
}
