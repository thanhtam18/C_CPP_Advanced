#include "stdio.h"

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

int binarySearch(int arr[], int length, int number){
    int left = 0;
    int right = length;
    while(left <= right){
        int mid = left + (right - left)/2;
        if(arr[mid] == number) return mid;
        else if(arr[mid] < number) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

void printArray(int arr[], int length){
    for(int i = 0; i < length; i++){
        printf("%d ",arr[i]);
    }
    printf("\r\n");
}

int main(int argc, char const *argv[])
{
    int array[] = {5,2,8,4,1,6,23,12,56,78};
    int length = sizeof(array)/ sizeof(array[0]);
    selectionSort(array,length);
    printArray(array,length);
    printf("%d",binarySearch(array,length,8));
    return 0;
}
