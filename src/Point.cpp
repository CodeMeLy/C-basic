#include<stdio.h>
#include<math.h>
typedef struct Point{
    int x;
    int y;
};
void enter(Point &input);
void setPoint(Point &setter, int x, int y);
float findDistance(Point start,Point end);
bool belongToFirstQuadrant(Point source);
bool belongToSecondQuadrant(Point source);
bool belongToThirdQuadrant(Point source);
bool belongToFourthQuadrant(Point source);
Point findPointNearHorizontal(Point first, Point second);
Point findPointNearVertical(Point first, Point second);
Point findPointNearOrigin(Point first, Point second);
Point findPointSymetricHorizontal(Point source);
Point findPointSymetricVertical(Point source);
Point findPointSymetricOrigin(Point source);
Point findPointSymetricFirstBisector(Point source);// tự làm
Point findPointSymetricSecondBisector(Point source);// tự làm
void checkQuadrant(Point source);// kiểm tra 1 điểm xem điểm đó ở góc phần tư thứ mấy
void printPoint(Point output);
void printPointSymetricHorizontal(Point source);
void printPointSymetricVertical(Point source);
void printPointSymetricOrigin(Point source);
void printDistance(Point start,Point end);
void printPointNearHorizontal(Point first, Point second);
void printPointNearVertical(Point first, Point second);
void printPointNearOrigin(Point first, Point second);
void menu(Point start, Point end);// tự làm
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
    printPointNearOrigin(start,end);
    printPointSymetricHorizontal(start);
    printPointSymetricVertical(start);
    printPointSymetricOrigin(start);
    checkQuadrant(start);
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
Point findPointNearOrigin(Point first, Point second){
    Point origin;
    setPoint(origin,0,0);
    float first_distance = findDistance(first,origin);
    float second_distance = findDistance(second,origin);
    return first_distance < second_distance ? first : second;
}
Point findPointSymetricHorizontal(Point source){
    Point dest;
    setPoint(dest,source.x,-source.y);
    return dest;
}
Point findPointSymetricVertical(Point source){
    Point dest;
    setPoint(dest,-source.x,source.y);
    return dest;
}
Point findPointSymetricOrigin(Point source){
    Point dest;
    setPoint(dest,-source.x,-source.y);
    return dest;
}
bool belongToFirstQuadrant(Point source){
    return source.x>0 && source.y>0;
}
bool belongToSecondQuadrant(Point source){
    return source.x<0 && source.y>0;
}
bool belongToThirdQuadrant(Point source){
    return source.x<0 && source.y<0;
}
bool belongToFourthQuadrant(Point source){
    return source.x>0 && source.y<0;
}
void checkQuadrant(Point source){
    if(belongToFirstQuadrant(source)){
        printf("\npoint belong to first quadrant!");
    }
    else if(belongToSecondQuadrant(source)){
        printf("\npoint belong to second quadrant!");
    }
    else if(belongToThirdQuadrant(source)){
        printf("\npoint belong to third quadrant!");
    }
    else{
        printf("\npoint not belong to fourth quadrant!");
    }
}
void printPointNearHorizontal(Point first, Point second){
    Point near_horizontal = findPointNearHorizontal(first,second);
    printf("\npoint near horizontal:");
    printPoint(near_horizontal);
}
void printPointNearVertical(Point first, Point second){
    Point near_vertical = findPointNearVertical(first,second);
    printf("\npoint near vertical:");
    printPoint(near_vertical);
}
void printPointNearOrigin(Point first, Point second){
    Point near_origin = findPointNearOrigin(first,second);
    printf("\npoint near origin:");
    printPoint(near_origin);
}
void printPointSymetricHorizontal(Point source){
    Point dest = findPointSymetricHorizontal(source);
    printf("\npoint symetric horizontal:");
    printPoint(dest);
}
void printPointSymetricVertical(Point source){
    Point dest = findPointSymetricVertical(source);
    printf("\npoint symetric vertical:");
    printPoint(dest);
}
void printPointSymetricOrigin(Point source){
    Point dest = findPointSymetricOrigin(source);
    printf("\npoint symetric origin:");
    printPoint(dest);
}