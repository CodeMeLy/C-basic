#include<stdio.h>
#include<math.h>
#include<string.h>
enum CompareResult{
    LARGER  = 1, EQUAL = 0, SMALLER = -1
};
typedef struct Fraction {
    int numerator, denominator;
};
int UCLN (int a, int b);
int BCNN (int a, int b);
void printValue(Fraction a);
void printCompareResult(Fraction a, Fraction b);
void enter(Fraction &input);
Fraction compact (Fraction a);
Fraction plus(Fraction a, Fraction b);
Fraction minus(Fraction a, Fraction b);
Fraction multi(Fraction a, Fraction b);
Fraction divide(Fraction a, Fraction b);
CompareResult compare(Fraction a, Fraction b);
int main(){
    Fraction a,b,c;
    enter(a);
    enter(b);
    printf("\nthe number fraction 1 after compact is ");
    a = compact(a);
    printValue(a);
    printf("\nthe number fraction 2 after compact is ");
    b = compact(b);
    printValue(b);
    printf("\nThe sum of fraction 1 and fraction 2:");
    c = plus(a,b);
    printValue(c);
    printf("\nThe minus of fraction 1 and fraction 2: ");
    c = minus(a,b);
    printValue(c);
    printf("\nThe multi of fraction 1 and fraction 2: ");
    c = multi(a,b);
    printValue(c);
    printf("\nThe divide of fraction 1 and fraction 2: ");
    c = divide(a,b);
    printValue(c);
    printf("\nThe compare of fraction 1 and fraction 2 is: ");
    printCompareResult(a,b);
    return 0;
}
int UCLN (int a, int b){
    a = abs(a);
    b = abs(b);
    while(a*b != 0){
        if(a > b){
            a %= b;
        } else {
            b %= a;
        }
    }
    return a+b;
}
int BCNN (int a, int b){
    return a * b/UCLN(a,b);
}
Fraction compact (Fraction a){
    Fraction c;
    c.numerator=a.numerator/UCLN(a.numerator, a.denominator);
    c.denominator= a.denominator/UCLN(a.numerator, a.denominator);
    return c;
}   
Fraction plus(Fraction a, Fraction b){
    Fraction c;
    c.numerator = a.numerator*b.denominator + b.numerator*a.denominator;
    c.denominator = a.denominator * b.denominator;
    return c;
}
Fraction minus(Fraction a, Fraction b){
    Fraction c;
    c.numerator = (a.numerator * b.denominator) - (b.numerator * a.denominator);
    c.denominator = a.denominator * b.denominator;
    return c;
}
Fraction multi(Fraction a, Fraction b){
    Fraction c;
    c.numerator = a.numerator*b.numerator;
    c.denominator = a.denominator*b.denominator;
    return c;
}
Fraction divide(Fraction a, Fraction b){
    Fraction c;
    c.numerator = a.numerator * b.denominator;
    c.denominator = a.denominator * b.numerator;
    return c;
}
void printValue(Fraction a){
    a = compact(a);
    printf("%d/%d", a.numerator, a.denominator);
}
CompareResult compare(Fraction a, Fraction b){
    CompareResult result = EQUAL;
    if (a.numerator * b.denominator > a.denominator * b.numerator){
        result = LARGER;
    } else if (a.numerator * b.denominator < a.denominator * b.numerator){
        result = SMALLER;
    }
    return result;
}
void printCompareResult(Fraction a, Fraction b){
    CompareResult  result = compare(a,b);
    if(result == LARGER){
        printf("fraction 1 > fraction 2");
    } else if (result == SMALLER){
        printf("fraction 1 < fraction 2");
    } else {
        printf("fraction 1 = fraction 2");
    }
}
void enter(Fraction &input){
    printf("\nenter number fraction : ");
    scanf("%d%d", &input.numerator, &input.denominator);
}