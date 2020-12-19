#include<stdio.h>
#define MAXSIZE 50
typedef struct Array{
    int numbers[MAXSIZE];
    int size;
};
void enter(Array &input);
void printValue(Array output);
int main(){
    Array array;
    enter(array);
    return 0;
}
void enter(Array &input){
    int temp;
    printf("enter amount of numbers: ");
    scanf("%d",&input.size);
    printf("enter value of numbers: \n");
    for(int index=0;index<input.size;index++){
        printf("value at %d position in numbers: ",index);
        scanf("%d",&temp);
        input.numbers[index] = temp;
    }
}
void printValue(Array output){
    printf("\nprint value of number: ");
    for (int index = 0; index < output.size; index++)
    {
        printf(" %d",output.numbers[index]);
    }    
}