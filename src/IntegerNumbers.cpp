#include<stdio.h>
#define MAXSIZE 50
void enter(int numbers[],int &amount_numbers);
int main(){
    int numbers[MAXSIZE];
    int amount_numbers;
    enter(numbers,amount_numbers);// nhap các giá trị mảng
}
void enter(int numbers[], int &amount_numbers){
    int temp;
    printf("enter amount of numbers: ");
    scanf("%d",&amount_numbers);
    printf("enter value of numbers: ");
    for(int index=0;index<amount_numbers;index++){
        printf("\n value at %d position in numbers: ",index);
        scanf("%d",&temp);
    }
}