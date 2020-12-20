/* Quản lis điểm sinh viên
* Mỗi sinh viên có tên, giới tính, điểm(toán, lý, hóa), điểm môn phụ
* Điểm môn phụ là điểm kĩ thuật nếu là nam, điểm nữ công nếu là nữ
*/
#include<stdio.h>
#include<string.h>
enum Gender{
    MALE = 1, FEMALE = 2
};
typedef struct Marks{
    float math;
    float physical;
    float chemistry;
};
union MinorMarks{// điểm môn phụ
    float committee_woman;// nu cong
    float technical;// ki thuat
};
typedef struct Student{
    char name[50];
    int gender;//1: nam,2: nu
    Marks marks;
    MinorMarks minor_marks;
};
void enter(Marks &input);
void enter(Student &input);
void printInfo(Student output);
int main(){
    Student student;
    enter(student);
    printInfo(student);
    return 0;
}
void enter(Marks &input){
    printf("\nEnter math marks:");
    scanf("%f",&input.math);
    printf("\nEnter physical marks:");
    scanf("%f",&input.physical);
    printf("\nEnter chemistry marks:");
    scanf("%f",&input.chemistry);
}
void enter(Student &input){
    fflush(stdin);
    printf("\nEnter name:");
    gets(input.name);
    printf("\nEnter gender:");
    scanf("%d", &input.gender);
    printf("\nEnter mark:");
    enter(input.marks);
    if(input.gender == MALE){
        printf("\nEnter technical marks:");
        scanf("%f",&input.minor_marks.technical);       
    } else{
        printf("\nEnter committee woman marks:");
        scanf("%f",&input.minor_marks.technical);   
    }
}
void printInfo(Student output){
    char gender[50];
    float minor_marks;
    //NOTE: doi gioi tinh sang chuoi, minor_marks
    if(output.gender == MALE){
        strcpy(gender,"male");
        minor_marks =output.minor_marks.technical;
    } else{
        strcpy(gender,"female");
        minor_marks =output.minor_marks.committee_woman;
    }
    printf("{name: %s,gender: %s,main mark: {math: %.2f,physical%.2f,chemistry: %.2f)},minor mark: %.2f}",output.name,gender,output.marks.math,output.marks.physical,output.marks.chemistry,minor_marks);

}