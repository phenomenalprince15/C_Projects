#include <stdio.h>
#include <time.h>

int main() {

    /*
    - Use of localtime() function
    - It returns a pointer
    */
    time_t now;
    struct tm *clock;

    time(&now);
    clock = localtime(&now);
    puts("Time details::");
    printf("Day of the year: %d\n", clock->tm_yday);
    printf("Day of the week: %d\n",clock->tm_wday);
    printf("Year: %d\n",clock->tm_year+1900); // add 1900 to get current year
    printf("Month: %d\n",clock->tm_mon+1); // becz it starts with zero
    printf("Day of the month: %d\n",clock->tm_mday);
    printf("Hour: %d\n",clock->tm_hour);
    printf("Minute: %d\n",clock->tm_min);
    printf("Second: %d\n",clock->tm_sec);

    // Formatting and printing the time as a string
    char time_string[64];
    strftime(time_string, sizeof(time_string), "Today is %A, %B %d, %Y\nIt is %r\n", clock);
    
    printf("%s", time_string); // Print the formatted time string

    return(0);
}