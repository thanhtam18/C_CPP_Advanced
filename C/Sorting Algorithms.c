#include "stdio.h"

void insertionSort(int arr[], int length){
    for(int i = 0; i < length -1; i++){
        for(int j = i; j >= 0; j--){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int length){
    for(int i = 0; i < length - 1; i++){
        int index = i;
        for(int j = i + 1; j < length; j++){
            if(arr[j] < arr[index])
            index = j;
        }
        int temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
}

void bubbleSort(int arr[], int length){
    for(int i = 0; i < length - 1; i++){
        for(int j = 0; j < length - i - 1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArray(int arr[], int length){
    for(int i = 0; i < length; i++){
        printf("%d ",arr[i]);
    }
    printf("\r\n");
}

int main(int argc, char const *argv[])
{
    int array[] = {5,2,8,4,1,6,23,12,76,54};
    int length = sizeof(array)/ sizeof(array[0]);
    insertionSort(array,length);
    //selectionSort(array,length);
    //bubbleSort(array,length);
    printArray(array,length);
    return 0;
}


