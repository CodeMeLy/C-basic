#include<stdio.h>
#define MAXSIZE 50
void enter(int numbers[],int &amount_numbers);
void printValues(int numbers[], int amount_numbers);
void printMaxValue(int numbers[], int amount_numbers);
int findMaxValue(int numbers[], int amount_numbers);
int main(){
    int numbers[MAXSIZE];
    int amount_numbers;
    enter(numbers,amount_numbers);// nhap các giá trị mảng
    printValues(numbers,amount_numbers);// xuat cac gia tri mang
    printMaxValue(numbers,amount_numbers);// xuất giá trị max
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
void printMaxValue(int numbers[], int amount_numbers){
    int max = findMaxValue(numbers,amount_numbers);
    printf("\n Max of number is: %d",max);
}
int findMaxValue(int numbers[], int amount_numbers){
    int firstIndex = 0;
    int max = numbers[firstIndex];
    for (int index = 1; index < amount_numbers; index++)
    {
        if(numbers[index]>max){
            max = numbers[index];
        }
    }
    return max;
}