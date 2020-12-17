#include<stdio.h>
typedef struct Point{
    int x;
    int y;
};
void enter(Point &input);
void printPoint(Point &output);
int main(){
    Point point;
    enter(point);
    printPoint(point);
    return 0;
}
void enter(Point &input){
    printf("enter x:");
    scanf("%d",&input.x);
    printf(" y:");
    scanf("%d",&input.y);
}
void printPoint(Point &output){
    printf("(%d,%d)",output.x,output.y);
}