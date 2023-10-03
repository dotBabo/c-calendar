#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int calendar(int ,int );
int starting_day(int,int,int);
int findNumDaysInMonth(int,int);
int createTable(int,int,int,int);
void printTable(char[30],int[6][7], char[7][4]);

int main (){
    int syear;
    int smon;
    char exit;
    bool on = true;

    
    printf("Welcome to the Calendar of Bab,\n");

    while (on == true) {
    printf("Please input the year in the format 'YYYY'\n\n");
    scanf("%d%*c", &syear);
    printf("\n");
    printf("Please input the month in the format 'MM'\n\n");
    scanf("%d%*c", &smon);
    printf("\n");
    calendar(syear,smon);
    printf("Would you like to exit the program? Press 'y' to exit and 'n' to print another month\n\n");
    scanf("%c",&exit);
    printf("\n");
        if (exit == 'y'){
            printf("Goodbye!\n");
            on = false;
        }
    }

}

int calendar(int year, int mon){
    int daysInMonth;
    int firstDay;
    

    daysInMonth = findNumDaysInMonth(year, mon);
    firstDay = starting_day(year, mon, 1);
    createTable(firstDay,daysInMonth,year,mon); 
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
    int dayOfweek = ((day + 13 * (mon + 1)/5 + k+ k / 4 +j /4 + 5 *j) + 5) % 7;
    
    return dayOfweek;
}

int createTable(int dayOne,int numDays, int year, int mon){
    int i,y;
    int j;
    int table[6][7];
    char str_year[5];
    char header[7][4];
    char title[30]= "";
    char months[12][10]= {"January","February","March","April","May","June","July", "August", "September","October","November", "December"};
    char days[7][4] = {"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};

    strcat(title, months[mon-1]);
    strcat(title, " - ");
    sprintf(str_year, "%d", year);
    strcat(title,str_year);

    for(y = 0; i < 7;i++){
        strncpy(header[i], days[i],sizeof(header[i]));
    }

    for (i = 0; i< 6; i++){
        for (j=0; j<7; j++){
            if(i == 0 && j < dayOne){
                table[i][j] = 0;
            }
            else if(i * 7 + j +1 -dayOne > numDays){
                table[i][j] = 0;
            }
            else {
            table[i][j] = (i * 7)+ j + 1-dayOne;
            }
        }
    }

    printTable(title,table,header);

    return 0;
}


void printTable(char title[30],int table[6][7], char header[7][4]){

    printf("%s\n\n",title);

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
    printf("\n");
}