#include<stdio.h>
typedef struct Complex{// so phuc
    float real_part;// phan thuc
    float virtual_part;// phan ao
};
void enter(Complex &input);// NOTE: nhap vao 1 so phuc
void printValue(Complex &output);// NOTE: xuat mot so phuc
int main(){
    Complex complex;
    enter(complex);
    printValue(complex);
    return 0;
}
void enter(Complex &input){
    printf("\nenter real part:");
    scanf("%f",&input.real_part);
    printf("\nenter virtual part:");
    scanf("%f",&input.virtual_part);
}
void printValue(Complex &output){
    printf("%.2f + %.2fi", output.real_part, output.virtual_part);
}