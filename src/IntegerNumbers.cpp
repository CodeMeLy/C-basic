#include<stdio.h>
#define MAXSIZE 50
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
int main(){
    int numbers[MAXSIZE];
    int amount_numbers;
    int searchNumber = 4;
    enter(numbers,amount_numbers);// nhap các giá trị mảng
    printValues(numbers,amount_numbers);// xuat cac gia tri mang
    printMaxValue(numbers,amount_numbers);// xuất giá trị max
    printMinValue(numbers,amount_numbers);// xuat gia tri min
    digitsEvenNumbers(numbers,amount_numbers);// xuat so chan
    digitsOddNumbers(numbers,amount_numbers); // xuat so le  
    digitsPositionOfEvenNumbers(numbers,amount_numbers);// xuat vi tri so chan
    digitsPositionOfOddNumbers(numbers,amount_numbers);// xuat vi tri so le
    digitsPostionOfNumberByValue(numbers,amount_numbers,searchNumber);//liệt kê vị trí bởi giá trị cần tìm
    digitsPrimeNumbers(numbers,amount_numbers);// liệt kê số nguyên tố
    ascSort(numbers,amount_numbers);// sắp xếp tăng dần
    printValues(numbers,amount_numbers);// xuất sau khi sắp xếp
    descSort(numbers,amount_numbers); // sắp xếp giảm dần
    printValues(numbers,amount_numbers);// xuất sau khi sắp xếp
    printNumberOfPrimeNumbers(numbers,amount_numbers);
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
void printMaxValue(int numbers[], int amount_numbers){
    int max = findMaxValue(numbers,amount_numbers);
    printf("\n Max of number is: %d",max);
}
void printMinValue(int numbers[], int amount_numbers){
    int min = findMinValue(numbers,amount_numbers);
    printf("\n Min of number is: %d",min);
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
void digitsPrimeNumbers(int numbers[], int amount_numbers){
    printf("\nlist of prime numbers: ");
    for(int index = 0;index < amount_numbers;index++){
        int check_number = numbers[index];
        if(isPrimeNumber(check_number)){
            printf(" %d ",numbers[index]);
        }
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
void printNumberOfPrimeNumbers(int numbers[], int amount_numbers){
    int counter = countNumberOfPrimeNumbers(numbers,amount_numbers);
    printf("\nnumber of prime numbers: %d",counter);
}