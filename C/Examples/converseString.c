#include "stdio.h"
#include "stdint.h"


void reverseStringToNumber(char string[],int array[]){
    char *pCharacter = string;
    int countCharacter = 0;
    int count = 0;
    while (1){
        if( *(pCharacter + countCharacter) == ' ' || *(pCharacter + countCharacter) == '\0'){
            switch (countCharacter)
            {
            case 2:
                array[count] = 3;
                break;
            case 3:
                if(*(pCharacter) == 'm' && *(pCharacter+1) == 'o' && *(pCharacter+2) == 't')
                    array[count] = 1;
                else if(*(pCharacter) == 'h' && *(pCharacter+1) == 'a' && *(pCharacter+2) == 'i')
                    array[count] = 2;
                else if(*(pCharacter) == 'b' && *(pCharacter+1) == 'o' && *(pCharacter+2) == 'n')
                    array[count] = 4;   
                else if(*(pCharacter) == 'n' && *(pCharacter+1) == 'a' && *(pCharacter+2) == 'm')
                    array[count] = 5;
                else if(*(pCharacter) == 's' && *(pCharacter+1) == 'a' && *(pCharacter+2) == 'u')
                    array[count] = 6;   
                else if(*(pCharacter) == 'b' && *(pCharacter+1) == 'a' && *(pCharacter+2) == 'y')
                    array[count] = 7;
                else
                    array[count] = 8;                      
                break;
            case 4:
                if(*(pCharacter) == 'c' && *(pCharacter+1) == 'h' && *(pCharacter+2) == 'i' && *(pCharacter+3) == 'n')
                    array[count] = 9;
                else
                    array[count] = 10;
                break;                              
            }
            count++;
            if(*(pCharacter + countCharacter) == '\0')
            {
                array[count] = NULL;
                break;
            }             
            pCharacter = pCharacter + countCharacter + 1;
            countCharacter = 0;
        }
        else
        {
            countCharacter += 1;
        }
    }
}

void sortArrayNumber(int array[]){
    int i = 0;
    while(array[i] != NULL){
        int j = 0;
        while (array[j+1] != NULL){   
            if(array[j] > array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
            j++;
        }
        i++;
    }
  
}

void displayOutput(int arrayNumber[]){
    char *array[] = {"mot","hai","ba","bon","nam","sau","bay","tam","chin","muoi"};
    int count = 1;
    int i = 0;
   while(arrayNumber[i+1] != NULL){
        if(arrayNumber[i+1] == arrayNumber[i]){
            count += 1;
        }
        else{
            printf("%s: xuat hien %d lan\r\n",array[arrayNumber[i]-1],count);
            count = 1;
        }
        i++;
    }
    printf("%s: xuat hien %d lan\r\n",array[arrayNumber[i]-1],count);
}

void display(char string[]){
    int arrayNumber[] = {0};
    reverseStringToNumber(string,arrayNumber); 
    sortArrayNumber(arrayNumber);
    displayOutput(arrayNumber); 
}

int main(int argc, char const *argv[])
{
    char string[] = "mot hai mot chin ba tam muoi bon chin bay nam mot ba tam chin nam muoi";
    display(string);
    return 0;
}