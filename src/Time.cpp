#include<stdio.h>
const int times[12] = {31,28,31,30,31,30,31,31,30,31,30,31};//thoi gian binh thường tu ngày từ tháng 1 đến tháng 12
typedef struct DateTime{
    int day;
    int month;
    int year;
};
void enter(DateTime &current);
void setDateTime(DateTime &current,int day,int month,int year);
bool isValid(DateTime date);
bool isLeapYear(int year);
DateTime findNextDate(DateTime current);
int countDateInYear(DateTime current);
int findDistance(DateTime begin, DateTime end);
void printDateTime(DateTime current);
void printNextDate(DateTime current);
void printNumberOfDateInYear(DateTime current); 
void printDistance(DateTime begin, DateTime end);
int main(){
    DateTime begin,end;
    enter(begin);
    printDateTime(begin);
    enter(end);
    printDateTime(end);
    printNextDate(begin);
    printNumberOfDateInYear(begin);
    printDistance(begin,end);
    return 0;
}
void enter(DateTime &date){
    do{
        printf("\nEnter date:");
        scanf("%d%d%d",&date.day,&date.month,&date.year);
    }while(!isValid(date));
}
void setDateTime(DateTime &date,int day,int month,int year){
    date.day = day;
    date.month = month;
    date.year = year;
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
DateTime findNextDate(DateTime current){
    DateTime next_date; 
    if(current.month==12 && current.day== 31){// ngày cuối năm
        setDateTime(next_date,1,1,current.year+1);
    } 
    else if(current.month==2 && isLeapYear(current.year)){// tháng 2 của năm nhuận
            if(current.day==29){
                setDateTime(next_date,1,current.month+1,current.year);
            }
            else{
                setDateTime(next_date,current.day+1,current.month,current.year);

            }
        }
    else if(current.day == times[current.month-1]){// trùng ngày cuối tháng
            setDateTime(next_date,1,current.month+1,current.year);
    } else{// ngày bình thường
            setDateTime(next_date,current.day+1,current.month,current.year);
    }
    return next_date;
}
int countDateInYear(DateTime current){
    int counter = 0;
    for(int month=1;month<current.month;month++){
        counter+= times[month-1];//do dùng mảng, mảng bắt đầu từ 0
    }
    counter+=current.day;
    if(current.month>2){// năm nhuận có hơn 1 ngày
        counter+=1;
    }
    return counter;
}
int findDistance(DateTime begin, DateTime end){
    int counter = 0;
    if(begin.year > end.year){
        printf("\nbefore date must larger than last date");
    }
    else if(begin.month > end.month){
        printf("\nbefore date must larger than last date");
    }
    else if(begin.day > end.day){
        printf("\nbefore date must larger than last date");
    }
    else{
        int number_of_begin_date = 365;
        for(int year = begin.year+1; year < end.year;year++){// kiểm tra từ năm sau khi bắt đầu đến năm gần với năm kết thúc
            counter+=365;
            if(year%4==0){
                counter++;
            }
        }
        if(begin.year%4==0){
            number_of_begin_date +=1;
        }
        counter += (number_of_begin_date-countDateInYear(begin)) + countDateInYear(end);
    }
    return counter;
}
void printDateTime(DateTime date){
    printf("%d/%d/%d",date.day,date.month,date.year);
}

void printNextDate(DateTime current){
    DateTime next_date = findNextDate(current);
    printf("\nnext date:");
    printDateTime(next_date);
}
void printNumberOfDateInYear(DateTime current){
    int counter = countDateInYear(current);
    printf("\ncurrent day at %d in year",counter);
}
void printDistance(DateTime begin, DateTime end){
    int distance = findDistance(begin,end);
    printf("\nDistance of ");
    printDateTime(begin);
    printf(" and ");
    printDateTime(end);
    printf(": %d days",distance);
}