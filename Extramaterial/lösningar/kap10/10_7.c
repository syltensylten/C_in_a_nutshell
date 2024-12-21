/* 10_7.c */

#include <stdio.h>  /* printf(), puts(), scanf() */



/* Prototyper */
int  DayOfWeek(int day, int month, int year);
int  DaysInMonth(int month, int year);
void PrintMonth(int year, int month);


int main()
{
    int year, month;
    
    
    puts("KALENDERN\n");
    printf("Ange kalenderår: ");
    scanf("%d", &year);
    if (year < 1583)
        printf("År %d tillhör ej den gregorianska kalendern\n", year);
    else {
        printf("Ange månad: ");
        scanf("%d", &month);
        puts("\n");
        PrintMonth(year, month);
    }
}


int DayOfWeek(int day, int month, int year)
/* Beräkning enligt Zeller's algoritm. Mån = 0 .. Sön = 6 */
{
    int cent, r;
    
    if (month < 3) {
        --year; 
        month += 10;
    }
    else
        month -= 2;
    cent = year/100;
    year = year % 100;
    r = day - 1 + (13*month-1)/5 + year + year/4 - 2*cent + cent/4;
    return r % 7;
}


int DaysInMonth(int month, int year)
{
    switch (month) {
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                return 29;
            else
                return 28;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}


void PrintMonth(int year, int month)
{
    static char *dayArray[] =
    {"Mån", "Tis", "Ons", "Tor", "Fre", "Lör", "Sön"};
    
    static char *monthArray[] =
    {"Januari", "Februari", "Mars", "April", "Maj", "Juni",
        "Juli", "Augusti", "September", "Oktober", "November",
        "December"};
    
    int firstDay, lastDay, day, week, monthDay;
    
    printf("%10s %d\n", monthArray[month - 1], year);
    firstDay = DayOfWeek(1, month, year);  /* 0-6 */
    lastDay = firstDay + DaysInMonth(month, year) - 1;
    for (day = 0; day < 7; day++) {
        printf("%-4s", dayArray[day]);
        for (week = 0; week < 6; week++) {
            monthDay = 7*week + day;
            if (monthDay < firstDay)
                printf("   ");
            else if (monthDay <= lastDay)
                printf("%3d", monthDay - firstDay + 1);
        }
        printf("\n");
    }
}
