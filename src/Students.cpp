#include<stdio.h>
#define MAXSIZE 50
typedef struct DateTime{
    int day, month, year;
};
typedef struct Student{
    char name[50];
    float gpa;// diem trung binh
    DateTime date_of_birth;
};
typedef struct Students{
    Student students[MAXSIZE];
    int amount;
};
bool isLeapYear(int year);
bool isValid(DateTime checker);
void enter(DateTime &current);// sử dụng lại bài sửa rồi
void enter(Student &input);
void enter(Students &input);
int main(){
    Students list;
    enter(list);
    return 0;
}
void enter(DateTime &date){
    do{
        scanf("%d%d%d",&date.day,&date.month,&date.year);
    }while(!isValid(date));
}
void enter(Student &input){
    fflush(stdin);
    printf("\nenter name:");
    gets(input.name);
    printf("\nenter date of birth:");
    enter(input.date_of_birth);
    printf("\nenter GPA:");
    scanf("%f",&input.gpa);
}
void enter(Students &input){
    printf("amount of students:");
    scanf("%d",&input.amount);
    printf("\n enter list of students:");
    for(int position = 0;position < input.amount;position++){
        enter(input.students[position]);
    }
}
bool isLeapYear(int year){
    return year%4 == 0;
}
bool isValid(DateTime date){
    bool is_valid = true;
    if((date.month<1 && date.month >12)||(date.day<1)){
        is_valid = false;
    }else{
        switch(date.month){
            case 1:case 3: case 5: case 7: case 8: case 10: case 12:
                if(date.day>31){
                    is_valid = false;
                }
                break;
            case 4: case 6: case 9: case 11:
                if(date.day>30){
                    is_valid = false;
                }
                break;
            case 2: 
                if(isLeapYear(date.year) && date.day>29){
                    is_valid = false;
                }
                else if(!isLeapYear(date.year) &&date.day>28){
                    is_valid = false;
                }
            break;
        }
    }
    return is_valid;
}