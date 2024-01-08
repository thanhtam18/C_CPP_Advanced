#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int value;
    struct node* next;
}node;

node *createNode(int value); 
void push_back(node** array, int value); 
void push_front(node **array, int value); 
void pop_back(node **array); 
void pop_front(node **array); 
int front(node **array); 
int back(node **array); 
void insert(node **array, int value, int pos); 
void deletee(node **array, int pos); 
int size(node **array); 
int get(node *array, int pos); 
bool empty(node **array); 


void printList(node *temp){
    while(temp != NULL){
        printf("Value test: %d\n", temp->value);
        temp = temp->next;
    }
    printf("--------------------------\r\n");
}

int main()
{
    node* arr = NULL;
    empty(&arr) ? printf("True\r\n") : printf("False\r\n"); 
    push_back(&arr,3);
    push_front(&arr,5);
    insert(&arr,7,1);
    push_back(&arr,9);
    push_back(&arr,6);
    push_back(&arr,2);

    printList(arr);
    
    pop_back(&arr);
    pop_front(&arr);
    deletee(&arr,1);

    printList(arr);
    
    printf("Front: %d\n", front(&arr));
    printf("Back: %d\n", back(&arr));
    printf("Get position 1: %d\n", get(arr,1));
    printf("Size: %d\n", size(&arr));
    empty(&arr) ? printf("True\r\n") : printf("False\r\n");
	return 0;
}

node* createNode(int value)
{
    node* ptr = (node*)malloc(sizeof(node));
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}


void push_back(node** array, int value)
{
    node* temp;
    temp = createNode(value);
    if (*array == NULL){
        *array = temp;
    }
    else{
        node* p = *array;
        while (p->next != NULL){
            p = p->next;
        }
        p->next = temp;   
    }
}

void push_front(node **array, int value){
    node *temp;
    temp = createNode(value);
    if (*array == NULL){
        *array = temp;
    }
    else{
        temp->next = *array;
        *array = temp;
    }
}

void pop_back(node** array)
{
    if (*array == NULL){
        printf("Mang chua co gia tri");
        return;
    }
    node* p, * temp;
    p = *array;
    int i = 0;
    while (p->next->next != NULL){
        p = p->next;
        i++;
    }
    temp = p->next;
    p->next = NULL;
    free(temp);
}

void pop_front(node **array){
    if (*array == NULL){
        printf("Mang chua co gia tri");
        return;
    }
    node* temp = *array;
    *array = temp->next;
    free(temp);
}

void insert(node **array, int value, int pos){
    if (*array == NULL){
        printf("Mang chua co gia tri");
        return;
    }
    int index = 0;
    node *temp;
    node *p = *array;
    temp = createNode(value);
    while (p->next != NULL){
        if(index == pos - 1){
            temp->next = p->next;
            p->next = temp;
            return;
        }
        p = p->next;
        index++;
    }
    printf("Vi tri khong hop le\r\n");
}

void deletee(node **array, int pos){
    if (*array == NULL){
        printf("Mang chua co gia tri");
        return;
    }
    node *p = *array;
    node *temp;
    int index = 0;
    while(p->next != NULL){   
        if(index == pos - 1){
            temp = p;
        }
        else if(index == pos){
            temp->next = p->next;
            free(p);
            return;
        }
        p = p->next;
        index++;
    }
    printf("Vi tri khong hop le\r\n");
}



int front(node **array){
    if (*array == NULL){
        printf("Mang chua co gia tri");
        return 0;
    }
    node *temp = *array;
    return temp->value;
}

int back(node **array){
    if (*array == NULL){
        printf("Mang chua co gia tri");
        return 0;
    }
    node *temp = *array;
    while(temp->next != NULL){
        temp = temp->next;
    }
    return temp->value;
}

int get(node* array, int pos)
{
    int i = 0;
    while (array->next != NULL && pos != i){
        array = array->next;
        i++;
    }
    if (pos != i){
        printf("Error: List has less element\n");
        return 0;
    }
    int value = array->value;
    return value;
}

int size(node **array){
    int size = 0;
    node *temp = *array;
    while(temp != NULL){
        size++;
        temp = temp->next;
    }
    return size;
}

bool empty(node **array){
    if(*array == NULL)
        return true;
    return false;
}