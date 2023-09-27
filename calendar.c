#include <stdio.h>

int calendar(int ,int );
int starting_day(int,int,int);
int findNumDaysInMonth(int,int);

int main (){
    char months[12][4]={"Jan", "Feb","Mar", "Apr", "May","Jun","Jul","Aug","Sep","Oct", "Nov","Dec"};
    char days[7][4] = {"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
    int  syear;
    int smon;

    printf("Welcome to the Calendar of Bab,\n Please input the year in the format 'YYYY'\n\n");
    scanf("%d", &syear);
    printf("\nPLease input the month in the format 'MM'\n\n");
    scanf("%d", &smon);

    calendar(syear,smon);


}

int calendar(int year, int mon){
    int mon;
    int year;
    int daysInMonth;

    daysInMonth = findNumDaysInMonth(year, mon);
    
};
int findNumDaysInMonth(int year, int mon){
    if (mon == "Apr" || "June" || "Sep" ||"Nov"){
        return 30;
    }
    else if (mon == "Jan"|| "Mar"||"May"|| "Jul" || "Aug" ||"Oct"||"Dec" ){
        return 31;
    }
    else if (mon == "Feb"){
            if (year % 4 == 0){
                return 29;
            }
            else{
                return 28;
            }
    }




}


int starting_day(int year, int mon, int day){
    if (mon < 3){
        mon += 12;
        year--; 
    }

    int k = year % 100;
    int j = year / 100;
    int dayOfweek = (day + ((13 * (mon + 1)) / 5) + k + (k / 4) + (j / 4) - (2 * j)) % 7;
    
    return dayOfweek;
}