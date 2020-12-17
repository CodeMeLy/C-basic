#include<stdio.h>
#include<math.h>
typedef struct Point{
    int x;
    int y;
};
void enter(Point &input);
float findDistance(Point start,Point end);
void printPoint(Point output);
void printDistance(Point start,Point end);
int main(){
    Point start,end;
    enter(start);
    printPoint(start);
    printf("\n");
    enter(end);
    printPoint(end);
    printf("\n");
    printDistance(start,end);
    return 0;
}
void enter(Point &input){
    printf("enter x:");
    scanf("%d",&input.x);
    printf(" y:");
    scanf("%d",&input.y);
}
float findDistance(Point start,Point end){
    return sqrt(pow(start.x-end.x,2) + pow(start.y-end.y,2));
}
void printPoint(Point output){
    printf("(%d,%d)",output.x,output.y);
}
void printDistance(Point start,Point end){
    float distance = findDistance(start,end);
    printf("\nDistance of 2 point: %.2f",distance);
}