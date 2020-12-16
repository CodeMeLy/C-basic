#include<stdio.h>
#define MAXSIZE 50
void enter(int numbers[],int &amount_numbers);
void printValues(int numbers[], int amount_numbers);
int main(){
    int numbers[MAXSIZE];
    int amount_numbers;
    enter(numbers,amount_numbers);// nhap các giá trị mảng
    printValues(numbers,amount_numbers);// xuat cac gia tri mang
}
void enter(int numbers[], int &amount_numbers){
    int temp;
    printf("enter amount of numbers: ");
    scanf("%d",&amount_numbers);
    printf("enter value of numbers: \n");
    for(int index=0;index<amount_numbers;index++){
        printf("value at %d position in numbers: ",index);
        scanf("%d",&temp);
        numbers[index] = temp;
    }
}
void printValues(int numbers[], int amount_numbers){
    printf("\nprint value of number: ");
    for (int index = 0; index < amount_numbers; index++)
    {
        printf(" %d",numbers[index]);
    }
    
}