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

int main() {

    time_t now;
    int year, month, day;
    struct tm *clock;

    char *phase[8] = {
        "waxing crescent", "at first quarter",
        "waxing gibbous", "full", "waning gibbous",
        "at last quarter", "waning crescent", "new"
        };

    time(&now);
    clock = localtime(&now);

    year = clock->tm_year+1900;
    month = clock->tm_mon+1;
    day = clock->tm_mday;

    printf("Year: %d\n", year);
    printf("Month: %d\n",month);
    printf("Day of the month: %d\n",day);

    int res = moon_phase(year, month, day);
    printf("Moon phase: %d\n", res);

    printf("Phase: %s\n", phase[res]);

    return (0);
}

