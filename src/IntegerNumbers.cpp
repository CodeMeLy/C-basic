#include<stdio.h>
#define MAXSIZE 50
enum Selector{
    PRINT_VALUES = 1,PRINT_MAX_VALUE = 2,PRINT_MIN_VALUE = 3,PRINT_NUMBER_OF_PRIME = 4,
    DIGITS_EVEN_NUMBER = 5, DIGITS_ODD_NUMBER = 6,DIGITS_EVEN_POSITION = 7,DIGITS_ODD_POSITION = 8,DIGITS_POSITION = 9,DIGITS_PRIME = 10, 
    ASC_SORT = 11, DESC_SORT =12
};
int swap(int &source, int &dest);
bool isPrimeNumber(int &check_number);
void enter(int numbers[],int &amount_numbers);
int findMaxValue(int numbers[], int amount_numbers);
int finMinValue(int numbers[], int amount_numbers);
int countNumberOfPrimeNumbers(int numbers[], int amount_numbers);
void ascSort(int numbers[],int amount_numbers);
void descSort(int numbers[],int amount_numbers);
void printValues(int numbers[], int amount_numbers);
void printMaxValue(int numbers[], int amount_numbers);
void printMinValue(int numbers[], int amount_numbers);
void printNumberOfPrimeNumbers(int numbers[], int amount_numbers);
void digitsPostionOfNumberByValue(int numbers[], int amount_numbers,int searchNumber);
void digitsEvenNumbers(int numbers[], int amount_numbers);
void digitsPositionOfEvenNumbers(int numbers[], int amount_numbers);
void digitsOddNumbers(int numbers[], int amount_numbers);
void digitsPositionOfOddNumbers(int numbers[],int amount_numbers);
void digitsPrimeNumbers(int numbers[], int amount_numbers);
void menu(int numbers[], int amount_numbers);
int main(){
    int numbers[MAXSIZE];
    int amount_numbers;
    int searchNumber = 4;
    enter(numbers,amount_numbers);// nhap các giá trị mảng
    menu(numbers,amount_numbers);
}
int swap(int &source, int &dest){
    int temp = source;
    source = dest;
    dest = temp;
}
bool isPrimeNumber(int &check_number){
    bool is_prime_number = true;
    for(int previous_number = 2; previous_number<check_number;previous_number++){
        if(check_number%previous_number==0){
            is_prime_number = false;
            break;
        }
    }
    return is_prime_number;
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
int countNumberOfPrimeNumbers(int numbers[], int amount_numbers){
    int counter = 0;
    for(int index = 0;index < amount_numbers;index++){
        int check_number = numbers[index];
        if(isPrimeNumber(check_number)){
            counter++;
        }
    }
    return counter;
}
void printValues(int numbers[], int amount_numbers){
    printf("\nprint value of number: ");
    for (int index = 0; index < amount_numbers; index++)
    {
        printf(" %d",numbers[index]);
    }    
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
int findMinValue(int numbers[], int amount_numbers){
    int firstIndex = 0;
    int min = numbers[firstIndex];
    for (int index = 1; index < amount_numbers; index++)
    {
        if(numbers[index]<min){
            min = numbers[index];
        }
    }
    return min;
}
void ascSort(int numbers[],int amount_numbers){
    for(int index = 0; index < amount_numbers-1;index++){
        for(int next_index = index+1;next_index<amount_numbers;next_index++){
            if(numbers[index]>numbers[next_index]){
                swap(numbers[index],numbers[next_index]);// hoán vị 2 số
            }
        }
    }
}
void descSort(int numbers[],int amount_numbers){
    for(int index = 0; index < amount_numbers-1;index++){
        for(int next_index = index+1;next_index<amount_numbers;next_index++){
            if(numbers[index]<numbers[next_index]){
                swap(numbers[index],numbers[next_index]);// hoán vị 2 số
            }
        }
    }
}
void printMaxValue(int numbers[], int amount_numbers){
    int max = findMaxValue(numbers,amount_numbers);
    printf("\n Max of number is: %d",max);
}
void printMinValue(int numbers[], int amount_numbers){
    int min = findMinValue(numbers,amount_numbers);
    printf("\n Min of number is: %d",min);
}
void printNumberOfPrimeNumbers(int numbers[], int amount_numbers){
    int counter = countNumberOfPrimeNumbers(numbers,amount_numbers);
    printf("\nnumber of prime numbers: %d",counter);
}
void digitsEvenNumbers(int numbers[], int amount_numbers){
    printf("\nlist of even number in numbers: ");
    for(int index = 0; index < amount_numbers;index++){
        if(numbers[index] %2 ==0){
            printf("%d ",numbers[index]);
        }
    }
}
void digitsPositionOfEvenNumbers(int numbers[], int amount_numbers){
    printf("\nindex of even number in numbers: ");
    for(int index = 0; index < amount_numbers;index++){
        if(numbers[index] %2 ==0){
            printf("%d ",index);
        }
    }
}
void digitsOddNumbers(int numbers[],int amount_numbers){
    printf("\nlist of odd number in numbers: ");
    for(int index = 0; index < amount_numbers;index++){
        if(numbers[index] %2 !=0){
            printf("%d ",numbers[index]);
        }
    }
}
void digitsPositionOfOddNumbers(int numbers[], int amount_numbers){
    printf("\nindex of odd number in numbers: ");
    for(int index = 0; index < amount_numbers;index++){
        if(numbers[index] %2 !=0){
            printf("%d ",index);
        }
    }
}
void digitsPostionOfNumberByValue(int numbers[], int amount_numbers,int searchNumber){
    printf("\nindex of %d: ",searchNumber);
    for(int index = 0; index < amount_numbers;index++){
        if(numbers[index]==searchNumber){
            printf("%d ",index);
        }
    }
}
void digitsPrimeNumbers(int numbers[], int amount_numbers){
    printf("\nlist of prime numbers: ");
    for(int index = 0;index < amount_numbers;index++){
        int check_number = numbers[index];
        if(isPrimeNumber(check_number)){
            printf(" %d ",numbers[index]);
        }
    }
}
void menu(int numbers[], int amount_numbers){
    int menu_option;
    int exit_option;
    do{
        printf("\n---------------Menu-------------------");
        printf("\n1. xuat cac gia tri mang");
        printf("\n2. xuat cac gia tri max ");
        printf("\n3. xuat cac gia tri min");
        printf("\n4. xuat so luong so nguyen to");
        printf("\n5. liet ke so chan");
        printf("\n6. liet ke so le");
        printf("\n7. liet ke vi tri so chan");
        printf("\n8. liet ke vi tri so le");
        printf("\n9. liet ke vi tri boi gia tri can tim");
        printf("\n10. liet ke so nguyen to");
        printf("\n11. sap xep tang dan");
        printf("\n12. sap xep giam dan");
        printf("\nselect option:");
        scanf("%d",&menu_option);
        switch(menu_option){
            case PRINT_VALUES:
                printValues(numbers,amount_numbers);
                break;
            case PRINT_MAX_VALUE:
                printMaxValue(numbers,amount_numbers);
                break;
            case PRINT_MIN_VALUE:
                printMinValue(numbers,amount_numbers);
                break;
            case PRINT_NUMBER_OF_PRIME:
                printNumberOfPrimeNumbers(numbers,amount_numbers);
                break;
            case DIGITS_EVEN_NUMBER:
                digitsEvenNumbers(numbers,amount_numbers);
                break;
            case DIGITS_ODD_NUMBER:
                digitsOddNumbers(numbers,amount_numbers);
                break;
            case DIGITS_EVEN_POSITION:
                digitsPositionOfEvenNumbers(numbers,amount_numbers);
                break;
            case DIGITS_ODD_POSITION:
                digitsPositionOfOddNumbers(numbers,amount_numbers);
                break;
            case DIGITS_POSITION:
                int search_number;
                printf("enter value to find: ");
                scanf("%d",&search_number);
                digitsPostionOfNumberByValue(numbers,amount_numbers,search_number);
                break;
            case DIGITS_PRIME:
                digitsPrimeNumbers(numbers,amount_numbers);
                break;
            case ASC_SORT:
                ascSort(numbers,amount_numbers);
                printValues(numbers,amount_numbers);
                break;
            case DESC_SORT:
                descSort(numbers,amount_numbers);
                printValues(numbers,amount_numbers);
                break;
            default:
                printf("\noption is invalid!");
        }
        printf("\nDo you want exit? (enter 0 to exit)");
        scanf("%d",&exit_option);
    }while(exit_option);
}