#include <stdio.h>
#include <time.h>

int moon_phase(int year, int month, int day) {
    int d, g, e;

    d = day;
    if (month == 2) d += 32;
    else if (month > 2) d += 59+(month-3)*30.6 + 0.5;

    g = (year-1900)%19;
    e = (11&g + 29) % 30;
    if (e == 25 || e == 24) e++;

    return ((((e+d)*6+5)%177)/22 & 7);
}

int main(int argc, char *argv[]) {

    time_t now;
    struct tm *clock;
    int hour;
    int year, month, day; // for moon phase
    char *phase[8] = {
        "waxing crescent", "at first quarter",
        "waxing gibbous", "full", "waning gibbous",
        "at last quarter", "waning crescent", "new"
        };
    
    printf("Hello, Prince!\n");
    
    //time(&now);
    //printf("The computer thinks, Time now is %ld\n", now); // It prints a string seconds of tick-tocking
    //printf("%s", ctime(&now));

    time(&now);
    clock = localtime(&now);
    hour = clock->tm_hour;
    printf("Good ");
    if (hour < 12){
        printf("morning!");
    } else if(hour < 17) {
        printf("afternoon!");
    } else {
        printf("evening!");
    }
    putchar('\n');
    printf("%s", ctime(&now));

    // For Moon phase
    year = clock->tm_year+1900;
    month = clock->tm_mon+1;
    day = clock->tm_mday;

    int res = moon_phase(year, month, day);
    //printf("Moon phase: %d\n", res);
    printf("Moon phase: %s\n", phase[res]);

    if (argc > 1) {
        printf("%s\n", argv[1]);
    }

    return(0);
}