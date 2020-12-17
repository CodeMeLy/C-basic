#include<stdio.h>
typedef struct Fraction{// NOTE: phan so
    int numerator;// NOTE: tu so
    int denominator;// NOTE: mau so
};
void enter(Fraction &input);
void printValue(Fraction output);
int main(){
    Fraction fraction;
    enter(fraction);
    printValue(fraction);
    return 0;
}
void enter(Fraction &input){
    printf("enter numerator:");
    scanf("%d",&input.numerator);
    do{
        printf("enter denominator:");
        scanf("%d",&input.denominator);
    }while(input.denominator==0);
}
void printValue(Fraction output){
    printf("%d/%d",output.numerator,output.denominator);
}