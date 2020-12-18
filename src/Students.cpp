#include<stdio.h>
#define MAXSIZE 50
typedef struct DateTime{
    int  day, month, year;
};
typedef struct Student{
    char name[25];
    float mark;
    DateTime birth_of_date;
};
typedef struct Students{
    Student list[MAXSIZE];
    int amount;
};
void enter(DateTime &input);
void enter(Student &input);
void enter(Students &input);
void printValue(DateTime output);
void printValue(Student output);
void printValue(Students output);
int main(){
    Students list;
    enter(list);
    printValue(list);
    return 0;
}
void enter(DateTime &input){
    printf("\nenter day, month, year:");
    scanf("%d%d%d",&input.day,&input.month,&input.year);//NOTE: tụi e có thể copy cái điều kiện nhập vào ngày từ bài trước đã sửa bỏ vào
}
void enter(Student &input){
    printf("\nenter name:");
    fflush(stdin);// truoc gets thì thêm câu lệnh này
    gets(input.name);// nhap vao 1 chuoi
    printf("enter birth of date:");
    enter(input.birth_of_date);
    printf("enter mark:");
    scanf("%f",&input.mark);
}
void enter(Students &input){
    printf("enter number of students:");
    scanf("%d",&input.amount);
    for(int position =0; position < input.amount;position++){
        printf("enter student at %d", position);
        enter(input.list[position]);
    }
}
void printValue(DateTime output){
    printf("%d/%d/%d", output.day, output.month, output.year);
}
void printValue(Student output){
    printf("\n%s",output.name);
    printf(", ");
    printValue(output.birth_of_date);
    printf(", %.2f",output.mark);
}
void printValue(Students output){
    for(int position =0; position < output.amount; position++){
        printValue(output.list[position]);
    }
}