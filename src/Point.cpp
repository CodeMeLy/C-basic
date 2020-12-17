#include<stdio.h>
#include<math.h>
typedef struct Point{
    int x;
    int y;
};
void enter(Point &input);
void setPoint(Point &setter, int x, int y);
float findDistance(Point start,Point end);
Point findPointNearHorizontal(Point first, Point second);
Point findPointNearVertical(Point first, Point second);
void printPoint(Point output);
void printDistance(Point start,Point end);
void printPointNearHorizontal(Point first, Point second);
void printPointNearVertical(Point first, Point second);
int main(){
    Point start,end;
    enter(start);
    printPoint(start);
    printf("\n");
    enter(end);
    printPoint(end);
    printf("\n");
    printDistance(start,end);
    printPointNearHorizontal(start,end);
    printPointNearVertical(start,end);
    return 0;
}
void enter(Point &input){
    printf("enter x:");
    scanf("%d",&input.x);
    printf(" y:");
    scanf("%d",&input.y);
}
void setPoint(Point &setter, int x, int y){
    setter.x = x;
    setter.y = y;
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
Point findPointNearHorizontal(Point first, Point second){
    Point first_foot_of_height;// chan duong cao thu 1
    Point second_foot_of_height;
    setPoint(first_foot_of_height,first.x,0);
    setPoint(second_foot_of_height,second.x,0);
    float first_distance = findDistance(first,first_foot_of_height);
    float second_distance = findDistance(second,second_foot_of_height);
    return first_distance < second_distance ? first : second;
}
Point findPointNearVertical(Point first, Point second){
    Point first_foot_of_height;// chan duong cao thu 1
    Point second_foot_of_height;
    setPoint(first_foot_of_height,0,first.y);
    setPoint(second_foot_of_height,0,second.y);
    float first_distance = findDistance(first,first_foot_of_height);
    float second_distance = findDistance(second,second_foot_of_height);
    return first_distance < second_distance ? first : second;
}
void printPointNearHorizontal(Point first, Point second){
    Point near_horizontal = findPointNearHorizontal(first,second);
    printf("\n point near horizontal:");
    printPoint(near_horizontal);
}
void printPointNearVertical(Point first, Point second){
    Point near_horizontal = findPointNearVertical(first,second);
    printf("\n point near vertical:");
    printPoint(near_horizontal);
}