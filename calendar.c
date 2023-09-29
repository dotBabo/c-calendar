#include <stdio.h>
#include <string.h>

int calendar(int ,int );
int starting_day(int,int,int);
int findNumDaysInMonth(int,int);
int createTable(int);
void printTable(int[6][7], char[7][4]);

int main (){
    char months[12][4]={"Jan", "Feb","Mar", "Apr", "May","Jun","Jul","Aug","Sep","Oct", "Nov","Dec"};
    int  syear;
    int smon;

    printf("Welcome to the Calendar of Bab,\n Please input the year in the format 'YYYY'\n\n");
    scanf("%d", &syear);
    printf("\nPLease input the month in the format 'MM'\n\n");
    scanf("%d", &smon);

    calendar(syear,smon);


}

int calendar(int year, int mon){
    int daysInMonth;
    int firstDay;
    

    daysInMonth = findNumDaysInMonth(year, mon);
    firstDay = starting_day(year, mon, 1);
    createTable(firstDay);

    
}

int findNumDaysInMonth(int year, int mon){
    if (mon == 4|| mon == 6 || mon == 9 ||mon == 11){
        return 30;
    }
    else if (mon == 1|| mon == 3||mon == 5|| mon == 7 || mon == 8 ||mon == 10||mon == 12 ){
        return 31;
    }
    else if (mon == 2){
            if (year % 4 == 0){
                return 29;
            }
            else{
                return 28;
            }
    }
}

int starting_day(int year, int mon, int day){
    /*This is done using Zeller's Congruence!
        Since i decided to do this in c like some crazy person I dont have access to libraries
        and so i had to fetch this on from geeks for geeks. Life savers here's the link
        "https://www.geeksforgeeks.org/zellers-congruence-find-day-date/"
     */
    if (mon < 3){
        mon += 12;
        year--; 
    }

    int k = year % 100;
    int j = year / 100;
    int dayOfweek = (day + ((13 * (mon + 1)) / 5) + k + (k / 4) + (j / 4) - (2 * j)) % 7;
    
    return dayOfweek;
}

int createTable(int dayOne){
    int i,y;
    int j;
    int table[6][7];
    char header[7][4];
    char days[7][4] = {"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};

    for(y = 0; i < 7;i++){
        strcpy(header[i], days[dayOne]);
        dayOne = (dayOne+ 1 ) % 7;
    }

    for (i = 0; i< 6; i++){
        for (j=0; j<7; j++){
            table[i][j] = (i * 7)+ j + 1;
        }
    }

    printTable(table,header);

    return 0;
}


void printTable(int table[6][7], char header[7][4]){
    for (int i = 0; i < 7; i++) {
        printf("%s\t", header[i]);
    }

    printf("\n");

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            printf("%d\t", table[i][j]);
        }
        printf("\n");
    }
}