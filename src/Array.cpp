#include<stdio.h>
#define MAXSIZE 50
typedef struct Array{
    int numbers[MAXSIZE];
    int size;
};
void enter(Array &input);
Array findEvenNumbers(Array source);
void printValue(Array output);
void printEvenNumbers(Array source);
int main(){
    Array array;
    enter(array);
    printf("\nprint value of number: ");
    printValue(array);
    printEvenNumbers(array);
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
    for (int index = 0; index < output.size; index++)
    {
        printf(" %d",output.numbers[index]);
    }    
}
Array findEvenNumbers(Array source){
    Array even_array;
    even_array.size = 0;
    for(int index = 0; index < source.size; index++){
        if(source.numbers[index]%2==0){
            even_array.size++;
            even_array.numbers[even_array.size-1] = source.numbers[index];
        }
    }
    return even_array;
}
void printEvenNumbers(Array source){
    Array even_array = findEvenNumbers(source);
    printf("\n Even numbers in array:");
    printValue(even_array);
}