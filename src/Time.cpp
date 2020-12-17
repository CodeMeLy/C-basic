#include<stdio.h>
typedef struct DateTime{
    int day;
    int month;
    int year;
};
void enter(DateTime &date);
bool isValid(DateTime date);
bool isLeapYear(int year);
void printDateTime(DateTime date);
int main(){
    DateTime date;
    enter(date);
    printDateTime(date);
    return 0;
}
void enter(DateTime &date){
    do{
        printf("Enter date:");
        scanf("%d%d%d",&date.day,&date.month,&date.year);
    }while(!isValid(date));
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
bool isLeapYear(int year){
    return year%4==0;
}
void printDateTime(DateTime date){
    printf("%d/%d/%d",date.day,date.month,date.year);
}