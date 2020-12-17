#include<stdio.h>
typedef struct Monomial{//NOTE: đơn thức
    float coefficients;//NOTE: hệ số
    int degree;//NOTE: bậc
};
void enter(Monomial &input);// NOTE: nhập đơn thức
void printValue(Monomial output);// NOTE: xuất đơn thức
int main(){
    Monomial monomial;
    enter(monomial);
    printValue(monomial);
    return 0;
}
void enter(Monomial &input){
    printf("enter coeffients:");
    scanf("%f",&input.coefficients);
    printf("enter degree:");
    scanf("%d",&input.degree);
}
void printValue(Monomial output){
    printf("%.2fx^%d",output.coefficients,output.degree);
}